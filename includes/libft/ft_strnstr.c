/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:08:48 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/13 11:36:31 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			j++;
			if (!needle[j])
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	str[] = "Helllo comment tu vas";
	char	fnd[] = "tU";

	printf("true strnstr: %s\n", strnstr(str, fnd, 10));
	printf("My: %s\n", ft_strnstr(str, fnd, 10));
	return (0);
}*/