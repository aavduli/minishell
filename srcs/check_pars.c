/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:02:39 by falberti          #+#    #+#             */
/*   Updated: 2024/07/09 14:50:10 by falberti         ###   ########.fr       */
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
	if (ft_strncmp(str, "$?", 2) == 0)
		return (CMD_LAST_EXIT);
	return (CMD_NONE);
}

int	is_valid_type(const char *str)
{
	const char	*invalid_chars;

	invalid_chars = "\\;&()";
	if (ft_strpbrk(str, invalid_chars) != NULL)
		return (0);
	return (1);
}
