/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:18:28 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/12 16:40:55 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	const char		*d;
	unsigned int	i;

	d = (const char *) s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (char) c)
			return ((void *)&d[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	str[] = "OpenAi";

	printf("character found: %p\n", ft_memchr(str, 'i', 8));
	return (0);
}*/