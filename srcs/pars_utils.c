/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:22:58 by falberti          #+#    #+#             */
/*   Updated: 2024/07/30 13:39:34 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_nb_strs(char **strs)
{
	int	nb;

	nb = 0;
	while (strs[nb])
		nb++;
	return (nb);
}

char	**ft_cpy_env(char **strs)
{
	int		i;
	char	**env;

	if (strs == NULL)
		return (NULL);
	env = malloc(sizeof(char *) * (get_nb_strs(strs) + 1));
	if (env == NULL)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		env[i] = ft_strdup(strs[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

void	check_update_type(t_data *data)
{
	t_cmd	*current;

	current = data->cmd;
	while (current != NULL)
	{
		if (current->prev && (current->prev->type == 4))
		{
			data->infile = ft_strdup(current->str);
			current->type = 11;
		}
		else if (current->prev && (current->prev->type == 5))
		{
			data->outfile = ft_strdup(current->str);
			current->type = 11;
		}
		else
			current->type = determine_type(current->str);
		if (current->type == 7 || current->type == 2)
			current->str = replace_env_variables(current->str, data);
		if (current->type == 7 || current->type == 2)
			current->type = 2;
		current = current->next;
	}
}
