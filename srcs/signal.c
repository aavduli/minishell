/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:26:02 by falberti          #+#    #+#             */
/*   Updated: 2024/06/12 15:58:44 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// TODO
static void	restore_prompt(int sig)
{
	write(1, "\n", 1);
	(void)sig;
}

static void	ctrl_c(int sig)
{
	write(1, "\n", 1);
	(void)sig;
}

void	run_signal(int sig)
{
	if (sig == 1)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 2)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 3)
	{
		printf("exit\n");
		exit(0);
	}
	//TODO
	if (sig == 4)
	{

	}
	return ;
}
