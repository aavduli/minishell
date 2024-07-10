/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:25:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/10 10:42:56 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_read_cmd(t_data *data)
{
	int	i;
	int	lst_size;

	lst_size = ft_lstsize(data->cmd->str);
	data->str = malloc(sizeof(char *) * (lst_size + 1));
	if (data->str == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (data->cmd->str)
	{
		while (data->cmd->str->type == 1 || data->cmd->str->type == 2)
		{
			data->str[i] = ft_strdup(data->cmd->str->str);
			data->cmd->str = data->cmd->str->next;
			i++;
		}
		if (data->cmd->str->type != 1 && data->cmd->str->type != 2)
		{
			data->str[i] = NULL;
			break ;
		}
		data->cmd->str = data->cmd->str->next;
	}
	ft_cmd(data);
	while (data->str[i])
	{
		free(data->str[i]);
		i++;
	}
	free(data->str);
}

void	ft_print_echo(t_data *data, int i, int j)
{
	while (data->str[i][j])
	{
		if (data->str[i][j + 1])
			ft_putchar_fd(data->str[i][j], 1);
		j++;
	}
}

void	ft_echo(t_data *data)
{
	int	i;
	int	j;
	int	n_flag;

	i = 1;
	j = 0;
	n_flag = 0;
	if (data->str[1] && ft_strncmp(data->str[1], "-n", 2) == 0)
	{
		n_flag = 1;
		i++;
	}
	while (data->str[i])
	{
		j = 0;
		if (data->str[i][0] == 34 || data->str[i][0] == 39)
			j++;
		ft_print_echo(data, i, j);
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (!n_flag)
		ft_putstr_fd("\n", 1);
}

void	ft_pwd(t_data *data)
{
	char	pwd[1024];

	(void)data;
	if (getcwd(pwd, sizeof(pwd)) != NULL)
	{
		ft_putstr_fd(pwd, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_cmd(t_data *data)
{
	if (ft_strncmp(data->str[0], "echo", 4) == 0)
		ft_echo(data);
	else if (ft_strncmp(data->str[0], "cd", 2) == 0)
		ft_cd(data);
	else if (ft_strncmp(data->str[0], "pwd", 3) == 0)
		ft_pwd(data);
	else if (ft_strncmp(data->str[0], "export", 6) == 0)
		ft_export(data);
	else if (ft_strncmp(data->str[0], "unset", 5) == 0)
		ft_unset(data);
	else if (ft_strncmp(data->str[0], "env", 3) == 0)
		ft_env(data);
	else if (ft_execute(data) == 1)
		return ;
	else
		ft_putstr_fd("minishell: command not found\n", 1);
}
