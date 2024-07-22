/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:01:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/22 14:16:58 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_reset_std(t_data *data)
{
	dup2(data->stdin, 0);
	dup2(data->stdout, 1);
	return ;
}

void	ft_stdin(t_data *data)
{
	int	fd;

	fd = open(data->infile, O_RDONLY);
	if (fd == -1)
	{
		printf("minishell: %s: %s\n", data->cmd->next->str, strerror(errno));
		return ;
	}
	dup2(fd, 0);
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
	dup2(fd, 1);
	close(fd);
}

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

void	execute_redir(t_data *data)
{
	t_cmd	*tmp;

	tmp = data->cmd;
	if (tmp->type == 4)
		ft_stdin(data);
	if ((tmp->type == 5 || tmp->type == 6) && tmp->next)
		ft_stdout(data);
}

void	check_redir(t_data *data, char **cmd)
{
	t_cmd	*tmp;

	tmp = data->cmd;
	if (tmp)
	{
		if (tmp->type == 3)
		{
			execute_pipeline(data, cmd);
		}
		if (tmp->type == 4 || tmp->type == 5 || tmp->type == 6)
			execute_redir(data);
	}
}
