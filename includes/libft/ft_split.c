/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:25:14 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/17 16:29:57 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include  <stdlib.h>

static size_t	ft_countword(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;
	size_t	len;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof (char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	lst[i] = 0;
	return (lst);
}
/*
int	main(void)
{
	char	**words;
	char	*string_to_split = "Hello   World! This is a test string.";
	char	delimiter = ' ';

	int i = 0;
	while (words[i] != NULL)
	{
		printf("Word %d: %s\n", i + 1, words[i]);
		free(words[i]);
		i++;
	}

	free(words);

	return (0);
}
*/