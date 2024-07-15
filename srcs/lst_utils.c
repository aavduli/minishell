/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:49:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/11 23:46:25 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	lst_cmd_size(t_data *data)
{
	int		size;
	t_cmd	*current;

	current = data->cmd;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
