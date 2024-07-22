/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:05:02 by falberti          #+#    #+#             */
/*   Updated: 2024/07/22 17:24:44 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*extract_variable_name(char *start, char **end)
{
	char	*var_end;
	size_t	var_len;
	char	*var_name;

	var_end = start;
	while (*var_end && (ft_isalnum(*var_end) || *var_end == '_'))
	{
		var_end++;
	}
	var_len = var_end - start;
	var_name = ft_strndup(start, var_len);
	*end = var_end;
	return (var_name);
}

static void	append_to_res(char **res, size_t *res_len, const char *to_app)
{
	size_t	new_len;
	char	*new_res;

	new_len = ft_strlen(*res) + ft_strlen(to_app);
	if (new_len >= *res_len)
	{
		*res_len = new_len + 1;
		new_res = realloc(*res, *res_len);
		if (!new_res)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		*res = new_res;
	}
	ft_strncat(*res, to_app, *res_len - ft_strlen(*res) - 1);
}

static char	*process_variable(char *p, char **res, size_t *res_len, t_data *d)
{
	char	*var_start;
	char	*var_end;
	char	*var_name;
	char	*var_value;

	var_start = p + 1;
	var_name = extract_variable_name(var_start, &var_end);
	if (!var_name)
	{
		free(*res);
		perror("strndup");
		exit(EXIT_FAILURE);
	}
	var_value = get_env_value(var_name, d);
	free(var_name);
	append_to_res(res, res_len, var_value);
	return (var_end);
}

static char	*ext_rev(t_data *d, char *r, size_t rl, const char *p)
{
	size_t	cl;
	char	*new_r;

	while (*p)
	{
		if (*p == '$')
		{
			p = process_variable((char *)p, &r, &rl, d);
			if (!p)
			{
				free(r);
				return (NULL);
			}
		}
		else
		{
			cl = ft_strlen(r);
			if (cl + 1 >= rl)
			{
				rl = rl * 2;
				new_r = realloc(r, rl);
				if (!new_r)
				{
					free(r);
					return (NULL);
				}
				r = new_r;
			}
			r[cl] = *p;
			r[cl + 1] = '\0';
			p++;
		}
	}
	return (r);
}

char	*replace_env_variables(const char *input, t_data *data)
{
	size_t		len;
	char		*result;
	size_t		result_len;
	const char	*p;

	len = ft_strlen(input);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	result[0] = '\0';
	result_len = len + 1;
	p = input;
	result = ext_rev(data, result, result_len, p);
	return (result);
}
