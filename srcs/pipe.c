/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:21:55 by aavduli           #+#    #+#             */
/*   Updated: 2024/08/05 16:14:40 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_stdin_inpipe(t_data *data)
{
	int	fd;

	if (data->infile)
	{
		fd = open(data->infile, O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		return (fd);
	}
	data->infile = NULL;
	return (STDIN_FILENO);
}

int	ft_stdout_inpipe(t_data *data)
{
	int	fd;

	if (data->outfile)
	{
		fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		return (fd);
	}
	data->outfile = NULL;
	return (STDOUT_FILENO);
}

void	exec_inpipe(t_data *data, char **cmd)
{
	char	*path;

	path = find_path(cmd[0], data->env);
	if (path == NULL || ft_strnstr(path, "/", 1) == NULL)
	{
		printf("minishell: path not found : %s\n", cmd[0]);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, data->env) == -1)
	{
		perror("execve");
		free(path);
		exit(EXIT_FAILURE);
	}
}

void	ft_cmd_inpipe(t_data *data, char **cmd)
{
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd[0], "cd", 2) == 0)
		ft_cd(cmd, data);
	else if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		ft_pwd(cmd);
	else if (ft_strncmp(cmd[0], "export", 6) == 0)
		ft_export(cmd, data);
	else if (ft_strncmp(cmd[0], "unset", 5) == 0)
	{
		if (cmd[1] == NULL)
			ft_putstr_fd("unset: not enough arguments\n", 1);
		else
			ft_unset(cmd, data);
	}
	else if (ft_strncmp(cmd[0], "env", 3) == 0)
		ft_env(data);
	else if (ft_strncmp(cmd[0], "./", 2) == 0)
		ft_mshell(data, cmd);
	else
		exec_inpipe(data, cmd);
	data->cmd->pipe = false;
}

void	execute_pipe(t_data *data, char **cmd, int in, int out)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (in != STDIN_FILENO)
		{
			dup2(in, STDIN_FILENO);
			close(in);
		}
		if (out != STDOUT_FILENO)
		{
			dup2(out, STDOUT_FILENO);
			close(out);
		}
		ft_cmd_inpipe(data, cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (in != STDIN_FILENO)
			close(in);
		if (out != STDOUT_FILENO)
			close(out);
	}
}

void	execute_pipeline(t_data *data, char ***cmd_tab)
{
	int		i;
	int		pipefd[2];
	int		in;
	int		out;

	i = 0;
	in = ft_stdin_inpipe(data);
	out = STDOUT_FILENO;

	while (i < data->pipe + 1)
	{
		if (i < data->pipe)
		{
			if (pipe(pipefd) == -1)
			{
				perror("pipe");
				exit(EXIT_FAILURE);
			}
			out = pipefd[1];
		}
		else
		{
			if (data->outfile)
				out = ft_stdout_inpipe(data);
			else
				out = STDOUT_FILENO;
		}
		execute_pipe(data, cmd_tab[i], in, out);
		if (in != STDIN_FILENO)
			close(in);
		if (out != STDOUT_FILENO)
			close(out);
		in = pipefd[0];
		i++;
	}
	if (in != STDIN_FILENO)
		close(in);
	while (wait(NULL) > 0)
		;
	ft_reset_std(data);
}
