/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:29:16 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/09 17:39:49 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isalnum(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	if (i >= 65 && i <= 90)
		return (1);
	if (i >= 97 && i <= 122)
		return (1);
	else
		return (0);
}

/*int	main(int argc, char **argv)
{
	argc = 1;
		printf("%d", ft_isalnum(*argv[1]));
	return (0);
}*/
