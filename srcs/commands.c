/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:25:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/08/07 13:46:49 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_mshell(t_data *data, char **cmd)
{
	int		status;
	int		pid;

	if (access(cmd[0], F_OK) == -1)
	{
		printf("minishell: commande not found : %s\n", cmd[0]);
		free_list(cmd);
		free_list(cmd);
		return ;
	}
	pid = fork();
	safe_pid(pid);
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, data->env) == -1)
			perror("execve\n");
		data->exit_status = 126;
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			data->exit_status = WEXITSTATUS(status);
	}
}

static void	ft_print_echo(char **cmd, int i, int j)
{
	while (cmd[i][j])
	{
		if (cmd[i][j] != 34 && cmd[i][j] != 39)
			ft_putchar_fd(cmd[i][j], 1);
		j++;
	}
}

void	ft_echo(char **cmd, t_data *d)
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
	d->exit_status = 0;
}

void	ft_pwd(char **cmd, t_data *d)
{
	char	pwd[1024];

	(void)cmd;
	if (getcwd(pwd, sizeof(pwd)) != NULL)
	{
		ft_putstr_fd(pwd, 1);
		ft_putstr_fd("\n", 1);
		d->exit_status = 0;
	}
}

void	ft_cmd(char **cmd, t_data *data)
{
	if (ft_strncmp(cmd[0], "echo", 5) == 0)
		ft_echo(cmd, data);
	else if (ft_strncmp(cmd[0], "cd", 7) == 0)
		ft_cd(cmd, data);
	else if (ft_strncmp(cmd[0], "pwd", 5) == 0)
		ft_pwd(cmd, data);
	else if (ft_strncmp(cmd[0], "export", 8) == 0)
		ft_export(cmd, data);
	else if (ft_strncmp(cmd[0], "unset", 7) == 0)
	{
		if (cmd[1] == NULL)
		{
			ft_putstr_fd("unset: not enough arguments\n", 1);
			data->exit_status = 1;
		}
		else
			ft_unset(cmd, data);
	}
	else if (ft_strncmp(cmd[0], "env", 4) == 0)
		ft_env(data);
	else if (ft_strncmp(cmd[0], "./minishell", 13) == 0)
		ft_mshell(data, cmd);
	else
		ft_execute(cmd, data);
}
