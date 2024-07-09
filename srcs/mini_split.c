/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:03:33 by falberti          #+#    #+#             */
/*   Updated: 2024/07/09 16:35:53 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdlib.h>
#include <ctype.h>

static int	ischar(char c)
{
	if (c == ' ' || c == '\t'
		|| c == '\n' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

static int	count_words(char const *str)
{
	int	i;
	int	count;
	int	trigger;
	int	in_quote;

	i = 0;
	count = 0;
	trigger = 0;
	in_quote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && in_quote == 0)
			in_quote = str[i];
		else if (str[i] == in_quote)
			in_quote = 0;
		if (!ischar(str[i]) && trigger == 0 && in_quote == 0)
		{
			trigger = 1;
			count++;
		}
		else if (ischar(str[i]) && in_quote == 0)
			trigger = 0;
		i++;
	}
	return (count);
}

static int	count_char(char const *str, int pos)
{
	int	i;
	int	in_quote;

	i = 0;
	in_quote = 0;
	while (str[pos + i] && (!ischar(str[pos + i]) || in_quote != 0))
	{
		if ((str[pos + i] == '\'' || str[pos + i] == '\"') && in_quote == 0)
			in_quote = str[pos + i];
		else if (str[pos + i] == in_quote)
			in_quote = 0;
		i++;
	}
	return (i);
}

static char	*create_new(char const *str, int *pos)
{
	char	*nstr;
	int		i;
	int		len;

	i = 0;
	len = count_char(str, *pos);
	nstr = (char *) malloc(sizeof(char) * (len + 1));
	if (nstr == 0)
		return (0);
	while (i < len)
	{
		nstr[i++] = str[*pos];
		(*pos)++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	**mini_split(char const *s)
{
	int		i;
	int		y;
	char	**liste;

	if (!s)
		return (0);
	liste = (char **) malloc(sizeof(*liste) * (count_words(s) + 1));
	if (liste == 0)
		return (0);
	i = 0;
	y = 0;
	while (s[i])
	{
		while (ischar(s[i]) && s[i])
			i++;
		if (s[i])
		{
			liste[y] = create_new(s, &i);
			y++;
		}
		while (!ischar(s[i]) && s[i])
			i++;
	}
	liste[y] = 0;
	return (liste);
}

// void	print_split(char **split)
// {
// 	int i = 0;
// 	while (split[i])
// 	{
// 		printf("Split[%d]: %s\n", i, split[i]);
// 		i++;
// 	}
// }
