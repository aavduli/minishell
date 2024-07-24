/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:33:20 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/24 13:36:02 by falberti         ###   ########.fr       */
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

// void	ft_read_lst(t_data *d)
// {
// 	char	**cmd;

// 	cmd = NULL;
// 	while (d->cmd)
// 	{
// 		if ((d->cmd->type >= 0 && d->cmd->type <= 2)
// 			|| (d->cmd->type >= 7 && d->cmd->type <= 8))
// 		{
// 			cmd = creat_tab(d, cmd);
// 			while (d->cmd && ((d->cmd->type >= 0 && d->cmd->type <= 2)
// 					|| (d->cmd->type >= 7 && d->cmd->type <= 8)))
// 				d->cmd = d->cmd->next;
// 		}
// 		if (d->cmd && ((d->cmd->type >= 3 && d->cmd->type <= 6)
// 				|| (d->cmd->type >= 9 && d->cmd->type <= 11)))
// 		{
// 			check_redir(d, cmd);
// 			while (d->cmd && ((d->cmd->type >= 3 && d->cmd->type <= 6)
// 					|| (d->cmd->type >= 9 && d->cmd->type <= 11)))
// 				d->cmd = d->cmd->next;
// 		}
// 		else if (cmd)
// 			ft_launch(d, cmd);
// 		if (d->cmd == NULL)
// 			return ;
// 	}
// }

void	ft_read_lst(t_data *data)
{
	char	**cmd;

	cmd = NULL;
	while (data->cmd)
	{
		if (data->cmd->type >= 0 && data->cmd->type <= 2)
		{
			cmd = creat_tab(data, cmd);
			printf("cmd2 = %s\n", cmd[1]);
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
			return ;
	}
}

// void	ft_read_lst(t_data *data)
// {
// 	char	**cmd;

// 	cmd = NULL;
// 	while (data->cmd)
// 	{
// 		if ((data->cmd->type >= 0 && data->cmd->type <= 2) || (data->cmd->type >= 7 && data->cmd->type <= 8))
// 		{
// 			cmd = creat_tab(data, cmd);
// 			while (data->cmd && ((data->cmd->type >= 0
// 						&& data->cmd->type <= 2) || (data->cmd->type >= 7 && data->cmd->type <= 8)))
// 				data->cmd = data->cmd->next;
// 		}
// 		if (data->cmd && ((data->cmd->type >= 3 && data->cmd->type <= 6)
// 				|| (data->cmd->type >= 9 && data->cmd->type <= 11)))
// 		{
// 			check_redir(data, cmd);
// 			while (data->cmd && ((data->cmd->type >= 3 && data->cmd->type <= 6)
// 					|| (data->cmd->type >= 9 && data->cmd->type <= 11)))
// 				data->cmd = data->cmd->next;
// 		}
// 		else if (cmd)
// 			ft_launch(data, cmd);
// 		if (data->cmd == NULL)
// 			return ;
// 	}
// }

char	**creat_tab(t_data *data, char **cmd)
{
	int		i;
	int		size;
	t_cmd	*current;

	current = data->cmd;
	size = lst_cmd_size(data);
	cmd = safe_malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (current && ((data->cmd->type >= 0 && data->cmd->type <= 2)
			|| data->cmd->type == 7 || data->cmd->type == 8))
	{
		cmd[i] = ft_strdup(current->str);
		current = current->next;
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
