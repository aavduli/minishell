/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:10:13 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/17 12:02:25 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
/*
char my_func(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c >= 'a' && c <= 'z') ? c - 32 : c;
	else
		return c;
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (0);
	str = (char *) malloc((ft_strlen(s) + 1) * sizeof (char));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main(void)
{
	char *src = "Exemple de chaine";
	char *result;

	result = ft_strmapi(src, my_func);
	if (result)
	{
		printf("Chaîne originale : %s\n", src);
		printf("Chaîne modifiée : %s\n", result);
	}
	else
	{
		printf("Échec de l'allocation mémoire\n");
	}
	return (0);
}*/