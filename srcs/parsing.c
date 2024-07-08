/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:49:41 by falberti          #+#    #+#             */
/*   Updated: 2024/07/08 14:09:10 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void  split_create_cmd_list(t_data *data, char *input)
{
	int		i;
	char	*token;
	t_cmd	*head;
	t_cmd	*tail;

	i = 0;
	token = mini_split(input);
	while (token[i] != NULL)
	{
		
	}
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
		ft_cmd(data);
		free(line);
		line = NULL;
	}
	return ;
}
