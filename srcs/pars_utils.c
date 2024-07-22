/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:22:58 by falberti          #+#    #+#             */
/*   Updated: 2024/07/22 17:26:39 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

static void	check_var_str(t_data *data, t_cmd *cmd)
{
	int		i;
	char	*cpy;
	size_t	var_len;

	if (cmd->str[0] == '$')
		cpy = cmd->str + 1;
	else
		cpy = cmd->str;
	var_len = ft_strlen(cpy);
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], cpy, var_len) == 0
			&& data->env[i][var_len] == '=')
		{
			free(cmd->str);
			cmd->str = ft_strdup(data->env[i] + var_len + 1);
			return ;
		}
		i++;
	}
	free(cmd->str);
	cmd->str = NULL;
}

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
		if (current->type == 7)
		{
			check_var_str(data, current);
		}
		current = current->next;
	}
	return ;
}
