/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:46:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/25 13:31:06 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_export(char **cmd, t_data *data)
{
	int	i;
	int	len;
	int	found;

	i = 0;
	found = 0;
	len = ft_strlen(cmd[1]);
	if (cmd[1] == NULL)
		ft_env(data);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], cmd[1], len) == 0)
		{
			ft_putstr_fd(data->env[i], 1);
			ft_putchar_fd('\n', 1);
			found = 1;
		}
		i++;
	}
	return (found);

}

void	ft_export(char **cmd, t_data *data)
{
	int	i;
	int	found;

	i = 0;
	while (cmd[i] != '=')
		i++;
	if (cmd[i] == '=')
	{
		i = 0;
		found = check_export(cmd, data);
		if (!found)
		{
			data->env[i] = ft_strdup(cmd[1]);
			data->env[i + 1] = NULL;
		}
	}
	return ;
}
