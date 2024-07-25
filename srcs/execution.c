/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:33:20 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/25 17:19:32 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_launch(t_data *data, char **cmd)
{
	if (!cmd)
		return ;
	if (cmd)
	{
		ft_cmd(cmd, data);
		ft_reset_std(data);
		free_tab(cmd);
	}
	else
		return ;
}

void	ft_read_lst(t_data *data)
{
	char	**cmd;
	t_cmd	*head;

	cmd = NULL;
	head = data->cmd;
	while (data->cmd)
	{
		if (data->cmd->type >= 0 && data->cmd->type <= 2)
		{
			cmd = creat_tab(data, cmd);
			while (data->cmd && data->cmd->type >= 0 && data->cmd->type <= 2)
				data->cmd = data->cmd->next;
		}
		if (data->cmd && (data->cmd->type >= 3 && data->cmd->type <= 11))
		{
			check_redir(data, cmd);
			while (data->cmd && (data->cmd->type >= 3 && data->cmd->type <= 11))
				data->cmd = data->cmd->next;
		}
		else if (cmd)
			ft_launch(data, cmd);
		if (data->cmd == NULL)
		{
			data->cmd = head;
			return ;
		}
	}
}

char	**creat_tab(t_data *data, char **cmd)
{
	int		i;
	int		size;
	t_cmd	*current;

	current = data->cmd;
	size = lst_cmd_size(data);
	if (cmd != NULL)
		free_list(cmd);
	cmd = safe_malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (current && (current->type >= 0 && current->type <= 2))
	{
		cmd[i] = ft_strdup(current->str);
		current = current->next;
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
