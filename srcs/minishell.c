/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:51:57 by falberti          #+#    #+#             */
/*   Updated: 2024/06/13 13:39:52 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_input(t_data *data)
{
	char	*line;
	size_t	len;
	int		nread;

	line = NULL;
	len = 0;
	nread = 0;
	(void)data;
	while (1)
	{
		printf("minishell> ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			perror("read line failed");
			break;
		}
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
	//init_data(&data);
	get_input(&data);
	return (0);
}
