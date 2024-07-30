/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:33:20 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/30 12:28:08 by aavduli          ###   ########.fr       */
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
	char	***cmd;
	int		i;

	i = 0;
	cmd = safe_malloc(sizeof(char **) * (count_commands(data) + 1));
	if (!cmd)
	{
		perror("safe_malloc");
		exit(EXIT_FAILURE);
	}
	while (data->cmd)
	{
		if (data->cmd->type >= 0 && data->cmd->type <= 2)
		{
			cmd[i] = creat_tab(data, cmd[i]);
			while (data->cmd && data->cmd->type >= 0 && data->cmd->type <= 2)
				data->cmd = data->cmd->next;
			i++;
		}
		if (data->cmd && (data->cmd->type >= 3 && data->cmd->type <= 11))
		{
			ft_reset_std(data);
			check_redir(data, cmd);
			while (data->cmd && (data->cmd->type >= 3 && data->cmd->type <= 11))
				data->cmd = data->cmd->next;
			break ;
		}
		else if (i > 0)
		{
			ft_launch(data, cmd[i - 1]);
		}
		if (data->cmd == NULL)
			break ;
	}
	free_tab(cmd);
}

char	**creat_tab(t_data *data, char **cmd)
{
	int		i;
	int		size;
	t_cmd	*current;

	current = data->cmd;
	size = lst_cmd_size(data);
	cmd = safe_malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (current && (current->type >= 0 && current->type <= 2))
	{
		cmd[i] = ft_shelldup(current->str);
		current = current->next;
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
