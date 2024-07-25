/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:46:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/24 17:48:25 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_export(char **cmd, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (cmd[1] == NULL)
		ft_env(data);
}

void	ft_export(char **cmd, t_data *data)
{
	int	i;
	int	j;
	int	found;

	j = 0;
	while (cmd[1][j] != '=' && cmd[1][j] != '\0')
		j++;
	i = 0;
	found = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], cmd[1], j) == 0)
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(cmd[1]);
			found = 1;
			break ;
		}
		i++;
	}
	if (!found)
	{
		data->env[i] = ft_strdup(cmd[1]);
		data->env[i + 1] = NULL;
	}
}
