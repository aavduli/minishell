/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:03:01 by aavduli           #+#    #+#             */
/*   Updated: 2024/08/05 18:03:14 by aavduli          ###   ########.fr       */
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
	return (STDIN_FILENO);
}

int	ft_stdout_inpipe(t_data *data)
{
	int		fd;
	t_cmd	*tmp;

	tmp = data->cmd;
	while (tmp->type != 5 && tmp->type != 6 && tmp->next)
		tmp = tmp->next;
	if (data->outfile)
	{
		if (tmp->type == 5)
			fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (tmp->type == 6)
			fd = open(data->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		return (fd);
	}
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
