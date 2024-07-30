/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:33:20 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/30 16:31:39 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_shelldup(const char *s1)
{
	char	*strr;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(s1);
	strr = malloc((size + 1) * sizeof(char));
	if (!strr)
		return (strr);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] != 34 && s1[i] != 39)
		{
			strr[j] = s1[i];
			j++;
		}
		i++;
	}
	strr[j] = '\0';
	return (strr);
}

void	ft_launch(t_data *data, char **cmd)
{
	if (!cmd)
		return ;
	if (cmd)
	{
		ft_cmd(cmd, data);
		ft_reset_std(data);
	}
	else
		return ;
}

void	ft_read_lst(t_data *data)
{
	char	***cmd_tab;

	cmd_tab = creat_tab(data);
	data->pipe = count_pipe(data);
	while (data->cmd)
	{
		if (data->cmd->type >= 4 && data->cmd->type <= 6)
		{
			ft_stdin(data);
			break ;
		}
		if (data->pipe > 0)
		{
			execute_pipeline(data, cmd_tab);
			break ;
		}
		else
		{
			ft_cmd(cmd_tab[0], data);
		}
		data->cmd = data->cmd->next;
	}
	ft_reset_std(data);
}

char	***creat_tab(t_data *data)
{
	int		i;
	int		j;
	int		size;
	char	***cmd_tab;
	t_cmd	*current;

	i = 0;
	j = 0;
	size = lst_cmd_size(data);
	cmd_tab = malloc((size + 1) * sizeof(char **));
	if (!cmd_tab)
		return (NULL);
	current = data->cmd;
	while (current)
	{
		if (current->type >= 0 && current->type <= 2)
		{
			cmd_tab[i] = malloc((count_cmd(current) + 1) * sizeof(char *));
			if (!cmd_tab[i])
				return (NULL);
			while (current && current->type >= 0 && current->type <= 2)
			{
				cmd_tab[i][j] = ft_shelldup(current->str);
				current = current->next;
				j++;
			}
			cmd_tab[i][j] = NULL;
			j = 0;
			i++;
		}
		else
			current = current->next;
	}
	cmd_tab[i] = NULL;
	return (cmd_tab);
}
