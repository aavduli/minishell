/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:14:41 by falberti          #+#    #+#             */
/*   Updated: 2024/07/25 15:56:05 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_exit(char *str, t_data *data)
{
	if (ft_strncmp(str, "exit", 4) == 0)
	{
		free(str);
		free_all(data);
		exit(0);
	}
	return (0);
}
