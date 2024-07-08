/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:49:41 by falberti          #+#    #+#             */
/*   Updated: 2024/07/08 15:40:34 by falberti         ###   ########.fr       */
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
	nn->type = check_str_type(str);
	nn->args = NULL;
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

static void	split_create_cmd_list(t_data *data, char *input)
{
	int		i;
	char	**token;
	t_cmd	*head;
	t_cmd	*tail;

	i = 0;
	head = NULL;
	tail = NULL;
	token = mini_split(input);
	while (token[i] != NULL)
	{
		tail = create_and_link_nodes(tail, token[i]);
		if (head == NULL)
			head = tail;
		i++;
	}
	data->cmd = head;
	free_list(token);
}

static	int	init_parsing(char *str, t_data *data)
{
	is_exit(str);
	split_create_cmd_list(data, str);
	if (*str != 0)
		printf("%s\n", str);
	return (0);
}

void	get_input(t_data *data)
{
	char	*line;

	(void)data;
	while (1)
	{
		run_signal(1);
		line = readline("minishell> ");
		if (line == NULL)
		{
			perror("read line failed");
			exit(0);
		}
		if (*line)
			add_history(line);
		init_parsing(line, data);
		//ft_cmd(data);
		free(line);
		line = NULL;
	}
	return ;
}
