/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:49:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/08/05 17:46:24 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_cmd(t_cmd *current)
{
	int	count;

	count = 0;
	while (current)
	{
		if (current->type >= 0 && current->type <= 2)
			count++;
		current = current->next;
	}
	return (count);
}

int	count_pipe(t_data *data)
{
	int		count;
	t_cmd	*current;

	current = data->cmd;
	count = 0;
	while (current)
	{
		if (current->type == 3)
			count++;
		current = current->next;
	}
	if (count > 0)
		data->cmd->pipe = true;
	return (count);
}

int	lst_cmd_size(t_data *data)
{
	int		size;
	t_cmd	*current;

	current = data->cmd;
	size = 0;
	while (current)
	{
		if (current->type >= 0 && current->type <= 2)
			size++;
		current = current->next;
	}
	return (size);
}

// t_cmd	*create_new_node(char *str)
// {
// 	t_cmd	*nn;

// 	nn = (t_cmd *)malloc(sizeof(t_cmd));
// 	if (nn == NULL)
// 	{
// 		perror("Failed to allocate memory");
// 		exit(EXIT_FAILURE);
// 	}
// 	nn->str = ft_strdup(str);
// 	nn->type = -1;
// 	nn->next = NULL;
// 	nn->prev = NULL;
// 	return (nn);
// }
