/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:25:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/06/19 16:00:16 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->env[i])
	{
		while (data->env[i][j] != '\0')
		{
			if (ft_strnstr(data->env[i], "PWD=", 4) == data->env[i])
			{
				ft_putstr_fd(data->env[i] + 4, 1);
				ft_putstr_fd("\n", 1);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_cmd(char *str, t_data *data)
{
	(void)str;
	// if (ft_strcmp(data.cmd->cmd, "echo") == 0)
	// 	ft_echo(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "cd") == 0)
	// 	ft_cd(data); //TODO
	//if (ft_strncmp(str, "pwd", 3) == 0)
	 	ft_pwd(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "export") == 0)
	// 	ft_export(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "unset") == 0)
	// 	ft_unset(data); //TODO
	// else if (ft_strcmp(data.cmd->cmd, "env") == 0)
	// 	ft_env(data); //TODO
	// else
	 //	execute(str, data); //TODO
}
