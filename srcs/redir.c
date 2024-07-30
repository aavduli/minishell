/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:01:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/30 16:31:02 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	execute_redir(t_data *data)
{
	if (data->cmd->type == 4)
		ft_stdin(data);
	if (data->cmd->type == 5 || data->cmd->type == 6)
		ft_stdout(data);
}
