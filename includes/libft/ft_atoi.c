/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:39:02 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/13 12:29:30 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while ((str[i] == 9) || (str[i] == 10) || (str[i] == 11)
		|| (str[i] == 12) || (str[i] == 13) || (str[i] == 32))
			i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

/*int main(void)
{
	const char *str1 = "   \t\n\v\f\r-42";
	const char *str2 = "   \t\n\v\f\r42";

	printf("Standard atoi: %d\n", atoi(str1));
	printf("ft_atoi: %d\n", ft_atoi(str1));

	printf("Standard atoi: %d\n", atoi(str2));
	printf("ft_atoi: %d\n", ft_atoi(str2));

	return (0);
}*/
