/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:49:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/30 11:59:10 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_pipe(t_data *data)
{
	t_cmd	*current;
	int		count;

	current = data->cmd;
	count = 0;
	while (current)
	{
		if (current->type == 3)
			count++;
		current = current->next;
	}
	return (count);
}

int	count_commands(t_data *data)
{
	t_cmd	*current;
	int		count;

	current = data->cmd;
	count = 0;
	while (current)
	{
		if (current->type >= 0 && current->type <= 2)
		{
			count++;
			while (current && current->type >= 0 && current->type <= 2)
				current = current->next;
		}
		if (current && (current->type >= 3 && current->type <= 11))
		{
			while (current && (current->type >= 3 && current->type <= 11))
				current = current->next;
		}
	}
	return (count);
}

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
