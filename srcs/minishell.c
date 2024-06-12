/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:51:57 by falberti          #+#    #+#             */
/*   Updated: 2024/06/12 15:57:33 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_input(t_data *data)
{
	char	*input;
	int		n;

	n = 0;
	while (n != 1)
	{
		run_signal(1);
		input = readline("minishell > ");
		if (input == NULL)
			exit(0);
		if (*input)
			add_history(input);
		data->str = ft_strdup(input);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	int			i;

	i = 0;
	(void)av;
	if (ac != 1)
		return 0;
  get_input(data);
	return (0);
}


