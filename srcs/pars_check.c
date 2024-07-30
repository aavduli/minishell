/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:02:39 by falberti          #+#    #+#             */
/*   Updated: 2024/07/30 13:37:02 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_strpbrk(const char *str, const char *accept)
{
	const char	*a;

	while (*str)
	{
		a = accept;
		while (*a)
		{
			if (*str == *a)
				return ((char *)str);
			a++;
		}
		str++;
	}
	return (NULL);
}

int	determine_type(const char *str)
{
	if (ft_strchr(str, '\'') != NULL)
		return (CMD_S_QUOTE);
	if (ft_strchr(str, '\"') != NULL)
		return (CMD_D_QUOTE);
	if (ft_strnstr(str, "<<", ft_strlen(str)) != NULL)
		return (CMD_HEREDOC);
	if (ft_strnstr(str, ">>", ft_strlen(str)) != NULL)
		return (CMD_APP_OUT_RED);
	if (ft_strchr(str, '<') != NULL)
		return (CMD_IN_RED);
	if (ft_strchr(str, '>') != NULL)
		return (CMD_OUT_RED);
	if (ft_strchr(str, '|') != NULL)
		return (CMD_PIPE);
	if (ft_strchr(str, '$') != NULL)
		return (CMD_ENV_VAR);
	return (CMD_NONE);
}

int	is_valid_type(const char *str)
{
	const char	*invalid_chars;
	int			s_quote;
	int			d_quote;
	int			i;

	invalid_chars = "\\;&()";
	s_quote = 0;
	d_quote = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && d_quote == 0)
			s_quote = !s_quote;
		if (str[i] == '\"' && s_quote == 0)
			d_quote = !d_quote;
		i++;
	}
	if (s_quote || d_quote)
		return (0);
	if (ft_strpbrk(str, invalid_chars) != NULL)
		return (0);
	return (1);
}
