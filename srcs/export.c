/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:46:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/25 15:08:15 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	len_to_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	found_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	check_export(char **cmd, t_data *data)
{
	int	i;
	int	egal;

	i = 0;
	egal = len_to_char(cmd[1], '=');
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], cmd[1], egal) == 0)
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(cmd[1]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_export(char **cmd, t_data *data)
{
	int	i;

	if (cmd[1] == NULL)
	{
		ft_env(data);
		return ;
	}
	i = 0;
	if (found_egal(cmd[1]))
	{
		i = 0;
		if (!check_export(cmd, data))
		{
			while (data->env[i])
				i++;
			data->env[i] = ft_strdup(cmd[1]);
			data->env[i + 1] = NULL;
		}
	}
	return ;
}
