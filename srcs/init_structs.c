/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:06:58 by falberti          #+#    #+#             */
/*   Updated: 2024/07/10 14:33:22 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_cmd(t_cmd *c)
{
	c->str = NULL;
	c->type = -1;
	c->next = NULL;
	c->prev = NULL;
}

void	init_data(t_data *d)
{
	d->cmd = NULL;
	d->nprompt = "minishell> ";
	d->exit_status = 0;
	d->env = NULL;
	d->original = NULL;
	return ;
}

// void	init_envp(char **envp)
// {
// 	ft_cpy_env(envp);
// 	return ;
// }
