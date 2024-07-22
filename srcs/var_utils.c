/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:47:37 by falberti          #+#    #+#             */
/*   Updated: 2024/07/22 17:13:24 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_env(char *name, t_data *data)
{
	size_t	name_len;
	int		i;

	name_len = ft_strlen(name);
	i = 0;
	while (data->env[i] != NULL)
	{
		if (ft_strncmp(data->env[i], name, name_len) == 0
			&& data->env[i][name_len] == '=')
		{
			printf("data->env me= %s\n", data->env[i]);
			//printf("INSIDE GET_ENV : %s\n", data->env[i] + (name_len + 1));
			return (data->env[i] + (name_len + 1));
		}
		i++;
	}
	return (NULL);
}

char	*get_env_value(char *var, t_data *data)
{
	char	*res;

	res = get_env(var, data);
	if (res != NULL)
		return (res);
	else
		return ("(NULL)");
}

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const char	*p;

	p = s;
	while (maxlen-- && *p)
	{
		p++;
	}
	return (p - s);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*new_str;

	len = ft_strnlen(s, n);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s, len);
	new_str[len] = '\0';
	return (new_str);
}

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	i;

	dest_len = strlen(dest);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
