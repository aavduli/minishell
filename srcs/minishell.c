/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:51:57 by falberti          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2024/06/19 11:06:50 by falberti         ###   ########.fr       */
=======
/*   Updated: 2024/06/17 13:10:00 by aavduli          ###   ########.fr       */
>>>>>>> 86d0a32 (updated my branch)
=======
/*   Updated: 2024/06/17 13:13:43 by aavduli          ###   ########.fr       */
>>>>>>> 92d760b (pipe & execute)
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

<<<<<<< HEAD
=======
int	init_parsing(char *str, t_data *data)
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
		line = readline("minishell> ");
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
		if (ft_strncmp(line, "exit", 4) == 0)
		{
			free(line);
			exit(0);
		}
	}
	return ;
}

>>>>>>> 86d0a32 (updated my branch)
int	main(int ac, char **av, char **envp)
{
	t_data	data;
	t_cmd	cmd;

	(void)av;
	if (ac != 1)
		return (0);
	init_data(&data);
	init_cmd(&cmd);
	data.env = ft_cpy_env(envp);
	data.original = ft_cpy_env(envp);
	// while (*data.original)
	// 	printf("%s\n", *data.original++);
	get_input(&data);
	return (0);
}
