/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:49:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/10 16:40:55 by aavduli          ###   ########.fr       */
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
		printf("Current: %s\n", current->str);
		size++;
		current = current->next;
	}
	printf("Size: %d\n", size);
	return (size);
}
