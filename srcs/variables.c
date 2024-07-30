/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:05:02 by falberti          #+#    #+#             */
/*   Updated: 2024/07/30 11:39:36 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void copy_exit(char *res, int *pos, t_data *data)
{
	char	*exit;
	int		i;

	exit = ft_itoa(data->exit_status);
	i = 0;
	while (exit[i])
	{
		res[*pos++] = exit[i++];
	}
	printf("Exit: %s\n", exit);
	free(exit);
	return ;
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
		printf("Test: %s \n", input);
		if (*input == '$' && *(input + 1) == '?')
		{
			printf("Exit: %s, %d\n", res, pos);
			copy_exit(res, &pos, data);
			input += 2;
		}
		else if (*input == '$')
		{
			printf("Exit: %s, %d\n", res, pos);
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

	printf("Test1: %s \n", input);
	p = input;
	len = get_full_size(p, data);
	printf("Test2: %s \n", p);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	p = input;
	printf("Test: %s \n", p);
	result = ext_rev(data, result, p);
	free(input);
	p = NULL;
	return (result);
}
