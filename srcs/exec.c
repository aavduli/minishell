/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:04:08 by avdylavduli       #+#    #+#             */
/*   Updated: 2024/08/07 13:52:27 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*part_pathing(char **paths, char *cmd)
{
	int		i;
	char	*path;
	char	*part_path;

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
	return (path);
}

char	**found_split(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == NULL)
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

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, F_OK) == 0)
			return (strdup(cmd));
		else
			return (NULL);
	}
	paths = found_split(envp);
	i = 0;
	if (!paths)
		return (NULL);
	path = part_pathing(paths, cmd);
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (path);
}

void	update_exit_status(int pid, t_data *data)
{
	int	status;

	run_signal(5);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		data->exit_status = WEXITSTATUS(status);
}

void	ft_execute(char **cmd, t_data *data)
{
	int		pid;
	char	*path;

	path = find_path(cmd[0], data->env);
	if (path == NULL)
	{
		printf("minishell: command not found : %s\n", cmd[0]);
		data->exit_status = 127;
		return ;
	}
	pid = fork();
	safe_pid(pid);
	if (pid == 0)
	{
		if (execve(path, cmd, data->env) == -1)
		{
			perror("execve\n");
			free(path);
			data->exit_status = 126;
			exit(EXIT_FAILURE);
			return ;
		}
	}
	free(path);
	update_exit_status(pid, data);
}
