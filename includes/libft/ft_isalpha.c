/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:58:14 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/16 17:58:35 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isalpha(int i)
{
	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
		return (1);
	else
		return (0);
}
/*
int	main(int argc, char **argv)
{
	argc = 1;
		printf("%d", ft_isalpha(*argv[1]));
	return (0);
}*/