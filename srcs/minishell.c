/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:51:57 by falberti          #+#    #+#             */
/*   Updated: 2024/06/25 12:00:10 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	t_cmd	cmd;
	int		i;
	int		j;

	j = 0;
	i = 1;
	if (ac != 1)
		return (0);
	while (av != NULL)
	{
		data.str[j] = av[i];
		j++;
		i++;
		printf("%s\n", *data.str);
	}
	init_data(&data);
	init_cmd(&cmd);
	data.env = ft_cpy_env(envp);
	data.original = ft_cpy_env(envp);
	get_input(&data);
	return (0);
}
