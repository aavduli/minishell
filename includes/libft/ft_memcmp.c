/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:42:54 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/13 11:21:26 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	const unsigned char	*s1_temp;
	const unsigned char	*s2_temp;
	unsigned int		i;

	i = 0;
	s1_temp = (const unsigned char *) s1;
	s2_temp = (const unsigned char *) s2;
	while (i < n)
	{
		if (s1_temp[i] != s2_temp[i])
			return (s1_temp[i] - s2_temp[i]);
		i++;
	}
	return (0);
}

/*int main(void)
{
	char str1[] = "OpenAI";
	char str2[] = "OpenAI";
	char str3[] = "OpenAi";


	int result = ft_memcmp(str1, str2, 6);
	printf("Result of comparison between str1 and str2: %d\n", result);


	result = ft_memcmp(str1, str3, 6);
	printf("Result of comparison between str1 and str3: %d\n", result);

	return (0);
}*/