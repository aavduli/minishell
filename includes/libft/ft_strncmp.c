/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:29:41 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/17 11:53:08 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	while (n)
	{
		if (*s1 != *s2 || !*s1 || !*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1)
			s1++;
		if (*s2)
			s2++;
		n--;
	}
	return (0);
}

/*int main(void)
{
	char	s1[] = "Coucouv";
	char	s2[] = "Coucous";

	printf("result: %d\n", ft_strncmp(s1, s2, 6));
	return (0);
}*/