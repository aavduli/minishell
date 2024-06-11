/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:49:04 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/16 15:40:23 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				neg;

	neg = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	str = (char *) malloc(sizeof (char) * (len + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		neg = -1;
		n = -n;
	}
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (neg == -1)
		str[0] = '-';
	return (str);
}

/*int	main(void)
{
	char	*result;


	result = ft_itoa(-2338);
	printf("Conversion de -2338 : %s\n", result);
	free(result);


	result = ft_itoa(0);
	printf("Conversion de 0 : %s\n", result);
	free(result);

	result = ft_itoa(2023);
	printf("Conversion de 2023 : %s\n", result);
	free(result);

	result = ft_itoa(-2147483648);
	printf("Conversion de INT_MIN : %s\n", result);
	free(result);

	return (0);
}*/