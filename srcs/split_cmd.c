/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:49:22 by albertini         #+#    #+#             */
/*   Updated: 2024/06/20 14:42:00 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static inline int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static	int	count_words(char *s)
{
	int	nb;

	nb = 0;
	while (*s && is_space(*s))
		*s++;
	while (*s)
	{
		if (*s && !is_space(*s))
			nb++;
		while (*s && !is_space(*s))
			*s++;
		while (*s && is_space(*s))
			*s++;
	}
	return (nb);
}

static int	count_char(char const *str)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]) == 0)
	{
		i++;
	}
	return (i);
}

static char	*create_new(char const *str, int pos)
{
	char	*nstr;
	int		i;
	int		len;

	i = 0;
	len = count_char(&str[pos]);
	nstr = (char *) malloc(sizeof(char) * len + 1);
	if (nstr == 0)
		return (nstr);
	while (i < len)
	{
		nstr[i] = str[pos];
		i++;
		pos++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	**split_cmd(char const *s)
{
	int		i;
	int		y;
	char	**liste;

	liste = (char **) malloc(sizeof(*liste) * (count_words(s) + 1));
	if (liste == 0)
		return (liste);
	i = 0;
	y = 0;
	while (s[i])
	{
		while (is_space(s[i]) == 1 && s[i])
			i++;
		if (s[i])
		{
			liste[y] = create_new(s, i);
			y++;
		}
		while (is_space(s[i]) == 0 && s[i])
			i++;
	}
	liste[y] = 0;
	return (liste);
}

