/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:14:38 by falberti          #+#    #+#             */
/*   Updated: 2024/07/10 15:25:07 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	free (list);
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
}

void	free_all(t_data *data)
{
	if (data->cmd != NULL)
		free_cmd(data->cmd);
	free_list(data->original);
	free_list(data->env);
	free_list(data->str);
	return ;
}
