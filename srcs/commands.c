/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:25:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/08 16:07:32 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	ft_echo(t_data *data)
// {
// 	int	i;
// 	int	n_flag;

// 	i = 1;
// 	n_flag = 0;
// 	if (data->str[1] && ft_strncmp(data->str[1], "-n", 2) == 0)
// 	{
// 		n_flag = 1;
// 		i++;
// 	}
// 	while (data->str[i])
// 	{
// 		ft_putstr_fd(data->str[i], 1);
// 		if (data->str[i + 1])
// 			ft_putstr_fd(" ", 1);
// 		i++;
// 	}
// 	if (!n_flag)
// 		ft_putstr_fd("\n", 1);
// }

// void	ft_pwd(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data->env[i])
// 	{
// 		if (ft_strncmp(data->env[i], "PWD=", 4) == 0)
// 		{
// 			ft_putstr_fd(data->env[i] + 4, 1);
// 			ft_putstr_fd("\n", 1);
// 			break ;
// 		}
// 		i++;
// 	}
// }

// void	ft_cmd(t_data *data)
// {
// 	if (ft_strncmp(data->str[0], "echo", 5) == 0)
// 		ft_echo(data);
// 	else if (ft_strncmp(data->str[0], "cd", 3) == 0)
// 		ft_cd(data);
// 	else if (ft_strncmp(data->str[0], "pwd", 4) == 0)
// 		ft_pwd(data);
// 	else if (ft_strncmp(data->str[0], "export", 7) == 0)
// 		ft_export(data);
// 	else if (ft_strncmp(data->str[0], "unset", 6) == 0)
// 		ft_unset(data);
// 	else if (ft_strncmp(data->str[0], "env", 4) == 0)
// 		ft_env(data);
// 	else if (ft_strncmp(data->str[0], "grep", 5) == 0)
// 		ft_execute(data);
// 	else
// 		ft_putstr_fd("minishell: command not found\n", 1);
// }
