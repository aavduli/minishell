/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:49:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/25 15:35:03 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	lst_cmd_size(t_data *data)
{
	int		size;
	t_cmd	*current;

	current = data->cmd;
	size = 0;
	while (current && (current->type >= 0 && current->type <= 2))
	{
		size++;
		current = current->next;
	}
	return (size);
}

t_cmd	*create_new_node(char *str)
{
	t_cmd	*nn;

	nn = (t_cmd *)malloc(sizeof(t_cmd));
	if (nn == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	nn->str = ft_strdup(str);
	nn->type = -1;
	nn->next = NULL;
	nn->prev = NULL;
	return (nn);
}
