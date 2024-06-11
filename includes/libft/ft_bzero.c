/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:43:20 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/12 14:13:45 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_bzero(void *s, unsigned int n)
{
	char	*str;

	str = (char *) s;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
}

/*int	main(void)
{
	char	str[] = "Coucou";

	printf("before: %s\n", str);
	ft_bzero(str, 4);
	printf("after: %s", str);
	return (0);
}*/
