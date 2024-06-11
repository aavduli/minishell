/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:34:37 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/13 16:27:11 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = (char *)malloc(sizeof (char) * ft_strlen(s1) + ft_strlen(s2) +1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str);
}
/*
int	main(void)
{
	char	*result;

	result = ft_strjoin("Hello, ", "world!");
	if (result)
	{
		printf("Test 1 result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Test 1 failed.\n");
	}
	result = ft_strjoin(NULL, "world!");
	if (result)
	{
		printf("Test 2 result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Test 2 failed (as expected).\n");
	}
	result = ft_strjoin("Hello, ", NULL);
	if (result)
	{
		printf("Test 3 result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Test 3 failed (as expected).\n");
	}
	result = ft_strjoin(NULL, NULL);
	if (result)
	{
		printf("Test 4 result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Test 4 failed (as expected).\n");
	}
	result = ft_strjoin("", "");
	if (result)
	{
		printf("Test 5 result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Test 5 failed.\n");
	}

	return (0);
}*/