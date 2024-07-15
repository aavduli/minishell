/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:04:08 by avdylavduli       #+#    #+#             */
/*   Updated: 2024/07/11 23:45:37 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**found_split(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	paths = found_split(envp);
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

int	ft_execute(char **cmd, t_data *data)
{
	int		i;
	int		status;
	int		pid;
	char	*path;

	i = -1;
	path = find_path(cmd[0], data->env);
	if (!path)
	{
		while (cmd[i++])
			free(cmd[i]);
		free(cmd);
		printf("prob with cmd\n");
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		printf("prob with fork\n");
		return (0);
	}
	else if (pid == 0)
	{
		if (execve(path, cmd, data->env) == -1)
			printf("prob with execve\n");
	}
	else
		waitpid(pid, &status, 0);
	free(path);
	return (1);
}
