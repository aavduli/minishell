/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:09:39 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/09 17:19:21 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	else
		return (0);
}

/*int	main(int argc, char **argv)
{
	argc = 1;
	printf("%d", ft_isdigit(*argv[1]));
	return (0);
}*/
