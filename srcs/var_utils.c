/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:47:37 by falberti          #+#    #+#             */
/*   Updated: 2024/07/23 12:01:25 by albertini        ###   ########.fr       */
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

int	get_full_size(char *str, t_data *data)
{
	int		nb;
	char	*var_value;
	char	*var_name;

	nb = 0;
	while (*str)
	{
		if (*str == '$')
		{
			var_name = extract_variable_name(str + 1);
			var_value = get_env_value(var_name, data);
			nb += ft_strlen(var_value);
			str += ft_strlen(var_name) + 1;
			free(var_name);
		}
		else
		{
			nb++;
			str++;
		}
	}
	return (nb);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*new_str;

	new_str = (char *)malloc(n + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s, n);
	new_str[n] = '\0';
	return (new_str);
}

char	*extract_variable_name(char *start)
{
	char		*var_name;
	size_t		i;

	i = 0;
	while (start[i] && (ft_isalnum(start[i]) || start[i] == '_'))
		i++;
	var_name = ft_strndup(start, i);
	return (var_name);
}
