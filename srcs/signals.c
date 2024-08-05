/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:26:02 by falberti          #+#    #+#             */
/*   Updated: 2024/08/05 17:36:08 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exist_status = 0;

static void	restore_prompt(int sig)
{
	g_exist_status = 1;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

	//rl_redisplay();
static void	restore_prompt_2(int sig)
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	(void)sig;
}

static void	heredoc(int sig)
{
	g_exist_status = 1;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	(void)sig;
}

static void	ctrl_c(int sig)
{
	write(1, "\n", 1);
	exit(0);
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
	if (sig == 4)
	{
		signal(SIGINT, heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 5)
	{
		signal(SIGINT, restore_prompt_2);
		signal(SIGQUIT, SIG_IGN);
	}
}
