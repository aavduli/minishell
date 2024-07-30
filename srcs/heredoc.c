/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:07:09 by albertini         #+#    #+#             */
/*   Updated: 2024/07/30 16:06:34 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_exist_status;

static void	handle_heredoc_line(int tmp_fd, char *delimiter, int var, t_data *d)
{
	char	*line;
	size_t	delim_len;

	delim_len = ft_strlen(delimiter);
	while (1)
	{
		run_signal(4);
		line = readline("heredoc> ");
		if (var == 1)
			line = replace_env_variables(line, d);
		if (!line || g_exist_status)
			break ;
		if (ft_strncmp(line, delimiter, delim_len) == 0
			&& line[delim_len] == '\0')
			break ;
		write(tmp_fd, line, ft_strlen(line));
		write(tmp_fd, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
}

static void	handle_heredoc(char *delimiter, int var, t_data *d)
{
	int		tmp_fd;
	char	*tmp_filename;

	g_exist_status = 0;
	tmp_filename = "/tmp/minishell_heredoc_tmp";
	tmp_fd = open(tmp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (tmp_fd == -1)
	{
		perror("minishell: open");
		return ;
	}
	handle_heredoc_line(tmp_fd, delimiter, var, d);
	if (g_exist_status)
		write(1, "Heredoc interrupted\n", 20);
	close(tmp_fd);
}

static void	redirect_heredoc_input(void)
{
	int		tmp_fd;
	char	*tmp_filename;

	tmp_filename = "/tmp/minishell_heredoc_tmp";
	tmp_fd = open(tmp_filename, O_RDONLY);
	if (tmp_fd == -1)
	{
		perror("minishell: open");
		return ;
	}
	if (dup2(tmp_fd, STDIN_FILENO) == -1)
	{
		perror("minishell: dup2");
		close(tmp_fd);
		return ;
	}
	close(tmp_fd);
}

void	execute_command_with_heredoc(char **com, char *del, int var, t_data *d)
{
	pid_t	pid;
	int		status;

	handle_heredoc(del, var, d);
	if (g_exist_status)
		return ;
	pid = fork();
	if (pid == -1)
	{
		perror("minishell: fork");
		return ;
	}
	if (pid == 0)
	{
		redirect_heredoc_input();
		execvp(com[0], com);
		perror("minishell: execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			d->exit_status = WEXITSTATUS(status);
	}
}
