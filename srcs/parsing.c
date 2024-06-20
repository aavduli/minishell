/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:49:41 by falberti          #+#    #+#             */
/*   Updated: 2024/06/20 14:55:19 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	int	init_parsing(char *str, t_data *data)
{
	if (*str != 0)
		printf("%s\n", str);
	data->str = ft_strdup(str);
	create_cmd(data);
	is_exit(str);
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
		ft_cmd(line, data);
		init_parsing(line, data);
		free(line);
		line = NULL;
	}
	return ;
}
