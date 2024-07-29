/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:25:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/29 13:45:55 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	increment_shlvl(t_data *data)
{
	int		i;
	char	*shlvl;
	int		shlvl_int;

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "SHLVL=", 6) == 0)
		{
			shlvl = ft_strdup(data->env[i] + 6);
			shlvl_int = ft_atoi(shlvl);
			shlvl_int++;
			free(data->env[i]);
			data->env[i] = ft_strjoin("SHLVL=", ft_itoa(shlvl_int));
			free(shlvl);
			break ;
		}
		i++;
	}
}

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
	if (ft_strncmp(cmd[0], "echo", 5) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd[0], "cd", 7) == 0)
		ft_cd(cmd, data);
	else if (ft_strncmp(cmd[0], "pwd", 8) == 0)
		ft_pwd(cmd);
	else if (ft_strncmp(cmd[0], "export", 9) == 0)
		ft_export(cmd, data);
	else if (ft_strncmp(cmd[0], "unset", 7) == 0)
	{
		if (cmd[1] == NULL)
			ft_putstr_fd("unset: not enough arguments\n", 1);
		else
			ft_unset(cmd, data);
	}
	else if (ft_strncmp(cmd[0], "env", 5) == 0)
		ft_env(data);
	else if (ft_strncmp(cmd[0], "./minishell", 12) == 0)
		ft_mshell(data, cmd);
	else
		ft_execute(cmd, data);
}
