/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/07/22 17:33:53 by aavduli          ###   ########.fr       */
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
	free_list(token);
}
/*
static void	print_cmd_list(t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current != NULL)
	{
		if (current->str != NULL)
		{
			printf("%s\n", current->str);
			printf("%d\n", current->type);
		}
		current = current->next;
	}
}*/
//print_cmd_list(data->cmd);

static	int	init_parsing(char *str, t_data *data)
{
	if (is_valid_type(str) == 0)
	{
		printf("Please enter a valid input!\n"
			"\\;&<>() are unvalid in this shell\n"
			"And quotes must be closed\n");
		return (0);
	}
	split_create_cmd_list(data, str);
	check_update_type(data);
	ft_read_lst(data);
	return (0);
}

static void	handle_line(t_data *data, char *line)
{
	char	*delimiter;
	char	*command;

	if (line[0] == '\0')
		return ;
	is_exit(line, data);
	if (ft_strnstr(line, "<<", ft_strlen(line)) != 0)
	{
		command = ft_strtok(line, " ");
		ft_strtok(NULL, " ");
		delimiter = ft_strtok(NULL, " ");
		if (command != NULL && delimiter != NULL)
			execute_command_with_heredoc(command, delimiter);
	}
	else
	{
		init_parsing(line, data);
	}
	if (data->cmd != NULL)
	{
		free_cmd(data->cmd);
		data->cmd = NULL;
	}
}

void	get_input(t_data *data)
{
	char	*line;

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
		handle_line(data, line);
		free(line);
		line = NULL;
	}
}
