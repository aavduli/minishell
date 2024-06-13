/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:51:57 by falberti          #+#    #+#             */
/*   Updated: 2024/06/13 16:10:33 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		init_parsing(char *str, t_data *data)
{
	(void)data;
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
		//printf("%s", data->nprompt);
		line  = readline("minishell> ");
		if (line == NULL)
		{
			perror("read line failed");
			exit(0);
		}
    if (*line)
      add_history(line);
    init_parsing(line, data);
		free(line);
		line = NULL;
	}
	return ;
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)envp;
	(void)av;
	if (ac != 1)
		return (0);
	init_data(&data);
	get_input(&data);
	return (0);
}
