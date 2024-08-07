/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:01:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/08/07 12:38:36 by aavduli          ###   ########.fr       */
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
	int		fd;
	t_cmd	*tmp;

	tmp = data->cmd;
	fd = STDIN_FILENO;
	while (tmp->type != 5 && tmp->type != 6 && tmp->next)
		tmp = tmp->next;
	if (tmp->type == 5)
		fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp->type == 6)
		fd = open(data->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		printf("minishell: %s: %s\n", tmp->next->str, strerror(errno));
		return ;
	}
	if (dup2(fd, 1) == -1)
	{
		printf("minishell: %s: %s\n", tmp->next->str, strerror(errno));
		return ;
	}
	close(fd);
}

void	check_redir(t_data *data, char ***cmd_tab)
{
	int		i;

	i = 0;
	while (cmd_tab[i + 1])
		i++;
	if (data->infile)
	{
		ft_stdin(data);
		free(data->infile);
		data->infile = NULL;
	}
	if (data->outfile)
	{
		ft_stdout(data);
		free(data->outfile);
		data->outfile = NULL;
	}
	ft_launch(data, cmd_tab[i]);
}
