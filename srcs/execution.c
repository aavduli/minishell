/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:33:20 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/16 15:20:34 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_read_lst(t_data *data)
{
	char	**cmd;

	cmd = NULL;
	while (data->cmd)
	{
		while (data->cmd->type >= 0 && data->cmd->type <= 2)
		{
			cmd = creat_tab(data, cmd);
			data->cmd = data->cmd->next;
		}
		if (data->cmd->type == 3)
			connect_pipe(data);
		data->cmd = data->cmd->next;
	}
}

char	**creat_tab(t_data *data, char **cmd)
{
	int		i;
	int		size;
	t_data	*current;

	current = data->cmd;
	size = lst_cmd_size(data);
	cmd = safe_malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (current->next)
	{
		if (current->type >= 0 && current->type <= 2)
		{
			cmd[i] = ft_strdup(current->str);
			i++;
		}
		current->cmd = current->next;
		if (data->cmd == NULL || data->cmd->type >= 3)
			break ;
	}
	cmd[i] = NULL;
	return (cmd);
}
