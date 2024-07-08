/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:49:41 by falberti          #+#    #+#             */
/*   Updated: 2024/07/08 15:38:40 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	int	init_parsing(char *str, t_data *data)
{
	data->str = NULL;
	is_exit(str);
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
