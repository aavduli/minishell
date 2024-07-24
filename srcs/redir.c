/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:01:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/24 14:23:54 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_pipeline(t_data *data, char **cmd)
{
	int	pipefd[2];
	int	pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		ft_cmd(cmd, data);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		dup2(pipefd[0], 0);
		close(pipefd[1]);
	}
}

void	ft_stdin(t_data *data)
{
	int	fd;

	fd = open(data->infile, O_RDONLY);
	if (fd == -1)
	{
		printf("minishell: open failed for %s: %s\n",
			data->infile, strerror(errno));
		return ;
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		printf("minishell: dup2 failed for fd %d: %s\n", fd, strerror(errno));
		close(fd);
		return ;
	}
	close(fd);
}

void	ft_stdout(t_data *data)
{
	int	fd;

	if (data->cmd->type == 5)
		fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(data->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		printf("minishell: %s: %s\n", data->cmd->next->str, strerror(errno));
		return ;
	}
	if (dup2(fd, 1) == -1)
	{
		printf("minishell: %s: %s\n", data->cmd->next->str, strerror(errno));
		return ;
	}
	close(fd);
}

void	execute_redir(t_data *data, char **cmd)
{
	if (data->cmd->type == 4)
		ft_stdin(data);
	else
	{
		ft_stdout(data);
		ft_cmd(cmd, data);
		ft_reset_std(data);
	}
}

void	check_redir(t_data *data, char **cmd)
{
	t_cmd	*tmp;

	tmp = data->cmd;
	if (tmp)
	{
		if (tmp->type == 3)
			execute_pipeline(data, cmd);
		if (tmp->type >= 4 && tmp->type <= 6)
		{
			execute_redir(data, cmd);
		}
	}
}
