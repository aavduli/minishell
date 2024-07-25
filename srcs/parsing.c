/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:49:41 by falberti          #+#    #+#             */
/*   Updated: 2024/07/25 17:39:18 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void print_cmd_list(t_cmd *head)
// {
//     t_cmd *current;

//     current = head;
//     while (current != NULL)
//     {
//         printf("Command: %s\n", current->str);
//         current = current->next;
//     }
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
	split_create_cmd_list(data, str);
	check_update_type(data);
	return (0);
}

static void	heredoc_var(t_data *data, char *line, int var)
{
	char	*delimiter;
	char	*command;

	command = ft_strtok(line, " ");
	ft_strtok(NULL, " ");
	delimiter = ft_strtok(NULL, " ");
	if (command != NULL && delimiter != NULL)
		execute_command_with_heredoc(command, delimiter, var, data);
}

static void	handle_line(t_data *data, char *line)
{
	t_cmd	*current;

	if (line[0] == '\0')
		return ;
	is_exit(line, data);
	if (ft_strnstr(line, "<<-", ft_strlen(line)) != 0)
		heredoc_var(data, line, 0);
	else if (ft_strnstr(line, "<<", ft_strlen(line)) != 0)
		heredoc_var(data, line, 1);
	else
	{
		init_parsing(line, data);
		current = data->cmd;
		ft_read_lst(data);
		data->cmd = current;
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
		handle_line(data, line);
		free(line);
		line = NULL;
	}
}
