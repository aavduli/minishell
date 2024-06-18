/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:30:27 by aavduli           #+#    #+#             */
/*   Updated: 2024/06/18 16:42:14 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**found_split_path(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH". 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	paths = found_split_path(envp);
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (path);
}

void	execute(t_data data)
{
	int		i;
	char	*path;

	i = -1;
	path = find_path(data->cmd.cmd, data->env);
	if (!path)
	{
		while (data->cmd.cmd[i++])
			free(data->cmd.cmd[i++]);
		free(data->cmd.cmd);
		error_exit("prob with cmd");
	}
	if (execve(path, data->cmd.cmd, data->env) == -1)
		error_exit("prob with execve");
	free(path);
}
