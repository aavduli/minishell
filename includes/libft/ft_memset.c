/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:24 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/12 14:14:35 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memset(void *b, int c, unsigned int len)
{
	char	*str;

	str = b;
	while (len)
	{
		*str = (unsigned char) c;
		str++;
		len--;
	}
	return (b);
}

/*int	main(void)
{
	char	str[25] = "Coucou";

	printf("Before: %s\n", str);
	printf("After: %s", ft_memset(str, 'A', 25));
	return (0);
}*/
