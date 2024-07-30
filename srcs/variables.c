/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:05:02 by falberti          #+#    #+#             */
/*   Updated: 2024/07/30 13:38:02 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	copy_exit(char *res, int *pos, t_data *data, char **input)
{
	char	*exit;
	int		i;

	exit = ft_itoa(data->exit_status);
	i = 0;
	while (exit[i])
	{
		res[*pos] = exit[i++];
		(*pos)++;
	}
	*input += 2;
	free(exit);
	return ;
}

int	get_full_size(char *str, t_data *data)
{
	int		nb;
	char	*var_value;
	char	*var_name;

	nb = 0;
	while (*str)
	{
		if (*str == '$' && *(str + 1) == '?')
			count_exit(&nb, &str, data);
		else if (*str == '$')
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

static char	*ext_rev(t_data *data, char *res, char *input)
{
	int		pos;
	int		i;
	char	*var_value;
	char	*var_name;

	pos = 0;
	while (*input)
	{
		if (*input == '$' && *(input + 1) == '?')
			copy_exit(res, &pos, data, &input);
		else if (*input == '$')
		{
			i = 0;
			var_name = extract_variable_name(input + 1);
			var_value = get_env_value(var_name, data);
			while (var_value[i])
				res[pos++] = var_value[i++];
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
	result[0] = '\n';
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
