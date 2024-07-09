/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:50:31 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/09 15:32:35 by aavduli          ###   ########.fr       */
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

void	ft_export(t_data *data)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], data->str[1],
				ft_strlen(data->str[1])) == 0)
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(data->str[1]);
			found = 1;
			break ;
		}
		i++;
	}
	if (!found)
	{
		data->env[i] = ft_strdup(data->str[1]);
		data->env[i + 1] = NULL;
	}
}

void	ft_unset(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], data->str[1],
				ft_strlen(data->str[1])) == 0)
		{
			free(data->env[i]);
			j = i;
			while (data->env[j + 1])
			{
				data->env[j] = data->env[j + 1];
				j++;
			}
			data->env[j] = NULL;
			break ;
		}
		i++;
	}
}

void	ft_cd(t_data *data)
{
	char	cwd[1024];
	int		i;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (data->str[1] == NULL)
			chdir(data->env[1]);
		else if (chdir(data->str[1]) == -1)
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
