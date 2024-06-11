/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:21:56 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/17 11:47:21 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

/*int main(void)
{
	char	str[] = "Auduv";
	printf("character foud: %s\n", ft_strchr(str, 'v'));
	return (0);
}*/