/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:25:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/06/19 14:04:44 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(t_data data)
{
	int	i;

	i = 0;
	while (data.env[i])
	{
		if (ft_strnstr(data.env[i], "PWD", 3) == 0)
		{
			ft_putstr_fd(data.env[i] + 4, 1);
			break ;
		}
	}
}

void	ft_cmd(t_data data)
{
	(void)data;
	// if (ft_strcmp(data.cmd->cmd, "echo") == 0)
	// 	ft_echo(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "cd") == 0)
	// 	ft_cd(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "pwd") == 0)
	// 	ft_pwd(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "export") == 0)
	// 	ft_export(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "unset") == 0)
	// 	ft_unset(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "env") == 0)
	// 	ft_env(data); //TODO
	// else
	// 	execute(data); //TODO
}
