/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:50:31 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/08 12:16:13 by aavduli          ###   ########.fr       */
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

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], data->str[1],
				ft_strlen(data->str[1])) == 0)
		{
			data->env[i] = ft_strjoin(data->str[1], data->str[2]);
			break ;
		}
		else if (data->env[i + 1] == NULL)
		{
			data->env[i + 1] = ft_strjoin(data->str[1], data->str[2]);
			break ;
		}
		i++;
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
			break ;
		}
		j = i;
		while (env[i])
		{
			data->env[j] = data->env[j + 1];
			j++;
		}
		i++;
	}
}

void	ft_cd(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i] == "PWD=", 4,) == 0)
		{
			if (chdir(data->str[1]) == -1)
				ft_putstr_fd("minishell: cd: no such file or directory\n", 1);
			else
			{
				data->env[i] = ft_strjoin("PWD=", data->str[1]);
				break ;
			}
		}
		i++;
	}
}
