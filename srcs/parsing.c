/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:49:41 by falberti          #+#    #+#             */
/*   Updated: 2024/07/16 13:25:57 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// static void	print_cmd_list(t_cmd *cmd)
// {
// 	t_cmd	*current;

// 	current = cmd;
// 	while (current != NULL)
// 	{
// 		if (current->str != NULL)
// 		{
// 			printf("%s\n", current->str);
// 			printf("%d\n", current->type);
// 		}
// 		current = current->next;
// 	}
// }
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
	is_exit(str, data);
	split_create_cmd_list(data, str);
	check_update_type(data);
	return (0);
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
		// if (ft_strnstr(line, "<<", 2) == 0)
		// 	heredoc(data, line);
		// else
		// 	init_parsing(line, data);
		init_parsing(line, data);
		ft_read_cmd(data);
		free(line);
		if (data->cmd != NULL)
		{
			free_cmd(data->cmd);
			data->cmd = NULL;
		}
		line = NULL;
	}
}
