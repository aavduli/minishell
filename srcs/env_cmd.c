/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:50:31 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/24 17:46:29 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		ft_putstr_fd(data->env[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	ft_unset(char **cmd, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strncmp(cmd[1], "PATH", 4) == 0)
	{
		ft_putstr_fd("minishell: PATH can't be unset\n", 1);
		return ;
	}
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], cmd[1],
				ft_strlen(cmd[1])) == 0)
		{
			free(data->env[i]);
			j = i;
			while (data->env[j + 1])
			{
				data->env[j] = data->env[j + 1];
				j++;
			}
			data->env[j] = NULL;
		}
		i++;
	}
}

void	ft_cd(char **cmd, t_data *data)
{
	char	cwd[1024];
	int		i;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (cmd[1] == NULL)
			chdir(data->env[1]);
		else if (chdir(cmd[1]) == -1)
		{
			ft_putstr_fd("cd: no such file or directory\n", 1);
			return ;
		}
		i = 0;
		while (data->env[i])
		{
			if (ft_strncmp(data->env[i], "PWD", 3) == 0)
			{
				free(data->env[i]);
				data->env[i] = ft_strjoin("PWD=", getcwd(cwd, sizeof(cwd)));
				break ;
			}
			i++;
		}
	}
}
