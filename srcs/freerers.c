/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:14:38 by falberti          #+#    #+#             */
/*   Updated: 2024/08/05 17:39:00 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_tab(char ***tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free_list(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_list(char **list)
{
	int	i;

	if (list == NULL)
		return ;
	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	list = NULL;
}

void	free_cmd(t_cmd *head)
{
	t_cmd	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		if (tmp->str)
			free(tmp->str);
		free(tmp);
	}
	head = NULL;
}

void	free_all(t_data *data)
{
	if (data->cmd != NULL)
		free_cmd(data->cmd);
	free_list(data->original);
	free_list(data->env);
	free(data->outfile);
	free(data->infile);
	data = NULL;
	return ;
}
