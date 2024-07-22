/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_backup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:48:01 by falberti          #+#    #+#             */
/*   Updated: 2024/07/22 17:11:37 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*extract_variable_name(char *start, char **end)
{
	char		*var_end;
	size_t		var_len;
	char		*var_name;

	var_end = start;
	while (*var_end && (ft_isalnum(*var_end) || *var_end == '_'))
		var_end++;
	var_len = var_end - start;
	var_name = ft_strndup(start, var_len);
	if (!var_name)
		return (NULL);
	*end = var_end;
	return (var_name);
}


static char	*append_to_result(char *r, size_t *r_len, char *str_to_append)
{
	size_t	new_len;

	new_len = ft_strlen(r) + ft_strlen(str_to_append);
	if (new_len >= *r_len)
	{
		*r_len = new_len + 1;
		r = realloc(r, *r_len);
		if (!r)
			return (NULL);
	}
	ft_strlcat(r, str_to_append, *r_len);
	printf("IN APPPEND: %s\n", r);
	return (r);
}


static char	*process_variable( char *p, char *r, size_t *r_len, t_data *d)
{
	char	*var_start;
	char	*var_end;
	char	*var_name;
	char	*var_value;

	var_start = p + 1;
	var_name = extract_variable_name(var_start, &var_end);
	if (!var_name)
	{
		free(r);
		return (NULL);
	}
	var_value = get_env_value(var_name, d);
	//printf("AZY TU SAOULES: %s\n", var_value);
	free(var_name);
	append_to_result(r, r_len, var_value);
	if (r == NULL)
		return (NULL);
	printf("AZY TU SAOULES: %s\n", r);
	return (var_end);
}

static char	*ext_rev(t_data *d, char *r, size_t rl, char *p)
{
	size_t	cl;

	printf("IN EXT REV1: %s\n", r);
	while (*p)
	{
		if (*p == '$')
		{
			process_variable(p, r, &rl, d);
			if (!p)
				return (NULL);
			printf("IN EXT REV2: %s\n", r);
		}
		else
		{
			cl = ft_strlen(r);
			r[cl] = *p;
			r[cl + 1] = '\0';
			printf("IN EXT REV4: %s\n", r);
			p++;
		}
	}
	printf("IN EXT REV5: %s\n", r);
	return (r);
}

char	*replace_env_variables(char *input, t_data *data)
{
	size_t		len;
	char		*result;
	size_t		result_len;
	char		*p;

	len = ft_strlen(input);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[0] = '\0';
	result_len = len + 1;
	p = input;
	result = ext_rev(data, result, result_len, p);
	printf("IN REPLACE: %s\n", result);
	return (result);
}
