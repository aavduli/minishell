/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:51:57 by falberti          #+#    #+#             */
/*   Updated: 2024/07/24 17:19:18 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//School : rl_clear_history() Home: clear_history
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
	get_input(&data);
	rl_clear_history();
	free_cmd(&cmd);
	return (0);
}
