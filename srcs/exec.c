/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:04:08 by avdylavduli       #+#    #+#             */
/*   Updated: 2024/07/16 17:41:09 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_mshell(t_data *data, char **cmd)
{
	int		status;
	int		pid;

	if (access(cmd[0], F_OK) == -1)
	{
		printf("minishell: commande not found : %s\n", cmd[0]);
		free_tab(cmd);
		return ;
	}
	pid = fork();
	safe_pid(pid);
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, data->env) == -1)
			perror("execve\n");
	}
	else
		waitpid(pid, &status, 0);
}

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
	if (!paths)
		return (NULL);
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

void	ft_execute(char **cmd, t_data *data)
{
	int		status;
	int		pid;
	char	*path;

	path = find_path(cmd[0], data->env);
	if (path == NULL || ft_strnstr(path, "/", 1) == NULL)
	{
		printf("minishell: path not found : %s\n", cmd[0]);
		free_tab(cmd);
		return ;
	}
	pid = fork();
	safe_pid(pid);
	if (pid == 0)
	{
		if (execve(path, cmd, data->env) == -1)
		{
			perror("minishell");
			return ;
		}
	}
	else
		waitpid(pid, &status, 0);
}
