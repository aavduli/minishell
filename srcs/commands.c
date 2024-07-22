/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:25:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/22 17:26:26 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_echo(char **cmd, int i, int j)
{
	while (cmd[i][j])
	{
		if (cmd[i][j] != 34 && cmd[i][j] != 39)
			ft_putchar_fd(cmd[i][j], 1);
		j++;
	}
}

void	ft_echo(char **cmd)
{
	int	i;
	int	j;
	int	n_flag;

	i = 1;
	j = 0;
	n_flag = 0;
	if (cmd[1] && ft_strncmp(cmd[1], "-n", 2) == 0)
	{
		n_flag = 1;
		i++;
	}
	while (cmd[i])
	{
		j = 0;
		ft_print_echo(cmd, i, j);
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (!n_flag)
		ft_putstr_fd("\n", 1);
}

void	ft_pwd(char **cmd)
{
	char	pwd[1024];

	(void)cmd;
	if (getcwd(pwd, sizeof(pwd)) != NULL)
	{
		ft_putstr_fd(pwd, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_cmd(char **cmd, t_data *data)
{
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd[0], "cd", 6) == 0)
		ft_cd(cmd, data);
	else if (ft_strncmp(cmd[0], "pwd", 4) == 0)
		ft_pwd(cmd);
	else if (ft_strncmp(cmd[0], "export", 7) == 0)
		ft_export(cmd, data);
	else if (ft_strncmp(cmd[0], "unset", 6) == 0)
		ft_unset(cmd, data);
	else if (ft_strncmp(cmd[0], "env", 4) == 0)
		ft_env(data);
	else if (ft_strncmp(cmd[0], "./", 2) == 0)
		ft_mshell(data, cmd);
	else
		ft_execute(cmd, data);
}
