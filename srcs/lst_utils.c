/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:49:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/10 14:58:57 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	*lst_cmd_size(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd->str)
	{
		while (data->cmd->type >= 0 && data->cmd->type <= 2)
		{
			i++;
			data->cmd = data->cmd->next;
		}
	}
	return (i);
}
