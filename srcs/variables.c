/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:05:02 by falberti          #+#    #+#             */
/*   Updated: 2024/07/23 16:13:15 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ext_rev(t_data *data, char *res, char *input)
{
	int		pos;
	int		i;
	char	*var_value;
	char	*var_name;

	pos = 0;
	while (*input)
	{
		if (*input == '$')
		{
			i = 0;
			var_name = extract_variable_name(input + 1);
			var_value = get_env_value(var_name, data);
			while (var_value[i])
			{
				res[pos++] = var_value[i++];
			}
			input += (ft_strlen(var_name) + 1);
			free(var_name);
		}
		else
			res[pos++] = *input++;
	}
	res[pos] = '\0';
	return (res);
}

char	*replace_env_variables(char *input, t_data *data)
{
	int			len;
	char		*result;
	char		*p;

	p = input;
	len = get_full_size(p, data);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	p = input;
	result = ext_rev(data, result, p);
	free(input);
	p = NULL;
	return (result);
}
