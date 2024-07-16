/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:07:09 by albertini         #+#    #+#             */
/*   Updated: 2024/07/16 17:41:30 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handle_heredoc_line(int tmp_fd, char *delimiter)
{
	char	*line;

	line = readline("heredoc> ");
	if (!line)
		return ;
	if (ft_strncmp(line, delimiter, ft_strlen(line)) == 0)
	{
		free(line);
		return ;
	}
	write(tmp_fd, line, ft_strlen(line));
	write(tmp_fd, "\n", 1);
	free(line);
	handle_heredoc_line(tmp_fd, delimiter);
}

static void	handle_heredoc(char *delimiter)
{
	int		tmp_fd;
	char	*tmp_filename;

	tmp_filename = "/tmp/minishell_heredoc_tmp";
	tmp_fd = open(tmp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (tmp_fd == -1)
	{
		perror("minishell: open");
		return ;
	}
	handle_heredoc_line(tmp_fd, delimiter);
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

void	execute_command_with_heredoc(char *command, char *delimiter)
{
	pid_t	pid;
	int		status;

	handle_heredoc(delimiter);
	pid = fork();
	if (pid == -1)
	{
		perror("minishell: fork");
		return ;
	}
	if (pid == 0)
	{
		redirect_heredoc_input();
		execlp(command, command, NULL);
		perror("minishell: execlp");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
}
