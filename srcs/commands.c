/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:25:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/06/20 15:36:11 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "PWD=", 4) == 0)
		{
			ft_putstr_fd(data->env[i] + 4, 1);
			ft_putstr_fd("\n", 1);
			break ;
		}
		i++;
	}
}

void	ft_cmd(t_data *data)
{
	// if (ft_strcmp(data.cmd->cmd, "echo") == 0)
	// 	ft_echo(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "cd") == 0)
	// 	ft_cd(data); //TODO
	if (ft_strncmp(data->str[0], "pwd", 3) == 0)
		ft_pwd(data);
	// else if (ft_strcmp(data.cmd->cmd, "export") == 0)
	// 	ft_export(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "unset") == 0)
	// 	ft_unset(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "env") == 0)
	// 	ft_env(data); //TODO
	else if (ft_strncmp(data->str[0], "grep", 4) == 0)
		ft_execute(data);
	else
		ft_putstr_fd("minishell: command not found\n", 1);
}
