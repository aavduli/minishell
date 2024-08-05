/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:06:58 by falberti          #+#    #+#             */
/*   Updated: 2024/08/05 13:52:17 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_cmd(t_cmd *c)
{
	c->str = NULL;
	c->type = -1;
	c->next = NULL;
	c->prev = NULL;
	c->pipe = false;
}

void	init_data(t_data *d)
{
	d->cmd = NULL;
	d->nprompt = "minishell> ";
	d->exit_status = 0;
	d->env = NULL;
	d->original = NULL;
	d->infile = NULL;
	d->outfile = NULL;
	d->stdin = dup(0);
	d->stdout = dup(1);
	d->out = 0;
	return ;
}

// void	init_envp(char **envp)
// {
// 	ft_cpy_env(envp);
// 	return ;
// }
