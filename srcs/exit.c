/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:14:41 by falberti          #+#    #+#             */
/*   Updated: 2024/08/07 13:59:47 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_exit(char *str, t_data *data)
{
	int		exit_num;
	char	*ptr;

	exit_num = 0;
	if (ft_strncmp(str, "exit", 4) == 0 && (str[4] == '\0'
			|| str[4] == ' ' || str[4] == '\t'))
	{
		ptr = str + 4;
		while (*ptr && ischar(*ptr))
			ptr++;
		if (*ptr && ft_isdigit(*ptr))
			exit_num = ft_atoi(ptr);
		free(str);
		free_all(data);
		exit(exit_num);
	}
	return (0);
}
