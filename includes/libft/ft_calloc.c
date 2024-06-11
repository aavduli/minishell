/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:31:33 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/13 13:58:13 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void	*mem;

	mem = malloc(count * size);
	if (!mem)
		return (0);
	ft_memset(mem, 0, count * size);
	return (mem);
}
/*
int	main(void)
{
	int				*int_array;
	char			*char_array;
	unsigned int	count;
	unsigned int	i;

	count = 5;
	int_array = (int *)ft_calloc(count, sizeof(int));
	if (int_array != NULL)
	{
		i = 0;
		while (i < count)
		{
			printf("int_array[%d]: %d\n", i, int_array[i]);
			i++;
		}
		free(int_array);
	}

	count = 10;
	char_array = (char *)ft_calloc(count, sizeof(char));
	if (char_array != NULL)
	{
		i = 0;
		while (i < count)
		{
			printf("char_array[%d]: %d\n", i, char_array[i]);
			i++;
		}
		free(char_array);
	}

	return (0);
}*/
