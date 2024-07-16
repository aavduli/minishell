/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:17:34 by falberti          #+#    #+#             */
/*   Updated: 2024/07/16 15:25:07 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static inline int	is_delim(char c, const char *delim)
{
	size_t	j;

	j = 0;
	while (delim[j] != '\0')
	{
		if (c == delim[j])
			return (1);
		j++;
	}
	return (0);
}

static char	*extract_token(char **save_str, char *token, const char *delim)
{
	size_t	i;

	i = 0;
	while ((*save_str)[i] != '\0')
	{
		if (is_delim((*save_str)[i], delim))
		{
			(*save_str)[i] = '\0';
			*save_str = &(*save_str)[i + 1];
			if (*token != '\0')
				return (token);
			return (ft_strtok(NULL, delim));
		}
		i++;
	}
	*save_str = NULL;
	if (*token == '\0')
		return (NULL);
	return (token);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*save_str;
	char		*token;

	if (str != NULL)
		save_str = str;
	if (save_str == NULL || *save_str == '\0')
		return (NULL);
	token = save_str;
	return (extract_token(&save_str, token, delim));
}
