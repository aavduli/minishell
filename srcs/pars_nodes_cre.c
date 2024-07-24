/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_nodes_cre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:25:12 by falberti          #+#    #+#             */
/*   Updated: 2024/07/24 16:02:50 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_cmd	*create_new_node(char *str)
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

static t_cmd	*create_and_link_nodes(t_cmd *tail, char *token)
{
	t_cmd	*new_node;

	new_node = create_new_node(token);
	if (tail == NULL)
		return (new_node);
	tail->next = new_node;
	new_node->prev = tail;
	return (new_node);
}

void	split_create_cmd_list(t_data *data, char *input)
{
	int		i;
	char	**token;
	t_cmd	*head;
	t_cmd	*tail;

	i = 0;
	head = NULL;
	tail = NULL;
	token = NULL;
	token = mini_split(input);
	data->str = mini_split(input);
	while (token[i] != NULL)
	{
		tail = create_and_link_nodes(tail, token[i]);
		if (head == NULL)
			head = tail;
		i++;
	}
	data->cmd = head;
	if (token != NULL)
		free_list(token);
}
