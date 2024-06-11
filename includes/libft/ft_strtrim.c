/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:41:43 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/13 18:20:00 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end --;
	trimmed_str = (char *) malloc(end - start + 2);
	if (!trimmed_str)
		return (0);
	ft_strlcpy(trimmed_str, &s1[start], end - start +2);
	return (trimmed_str);
}
/*
int	main(void)
{
	char	*result;

	// Test 1: Chaîne et ensemble de caractères normaux
	result = ft_strtrim("   Hello World   ", " ");
	if (result)
	{
		printf("Test 1 result: '%s'\n", result);
		free(result);
	}
	else
	{
		printf("Test 1 failed.\n");
	}

	// Test 2: Chaîne NULL
	result = ft_strtrim(NULL, " ");
	if (result)
	{
		printf("Test 2 result: '%s'\n", result);
		free(result);
	}
	else
	{
		printf("Test 2 failed (as expected).\n");
	}

	// Test 3: Ensemble de caractères NULL
	result = ft_strtrim("   Hello World   ", NULL);
	if (result)
	{
		printf("Test 3 result: '%s'\n", result);
		free(result);
	}
	else
	{
		printf("Test 3 failed (as expected).\n");
	}

	// Test 4: Chaîne et ensemble de caractères NULL
	result = ft_strtrim(NULL, NULL);
	if (result)
	{
		printf("Test 4 result: '%s'\n", result);
		free(result);
	}
	else
	{
		printf("Test 4 failed (as expected).\n");
	}

	// Test 5: Ensemble de caractères sans correspondance
	result = ft_strtrim("Helloz World", "z");
	if (result)
	{
		printf("Test 5 result: '%s'\n", result);
		free(result);
	}
	else
	{
		printf("Test 5 failed.\n");
	}

	return 0;
}*/