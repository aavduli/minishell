/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:14:38 by falberti          #+#    #+#             */
/*   Updated: 2024/07/08 16:32:36 by aavduli          ###   ########.fr       */
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
