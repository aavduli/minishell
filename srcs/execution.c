/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:33:20 by aavduli           #+#    #+#             */
/*   Updated: 2024/08/05 19:20:17 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_shelldup(const char *s1)
{
	char	*strr;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(s1);
	strr = malloc((size + 1) * sizeof(char));
	if (!strr)
		return (strr);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] != 34 && s1[i] != 39)
		{
			strr[j] = s1[i];
			j++;
		}
		i++;
	}
	strr[j] = '\0';
	return (strr);
}

void	ft_launch(t_data *data, char **cmd)
{
	if (!cmd)
		return ;
	if (cmd)
	{
		ft_cmd(cmd, data);
		ft_reset_std(data);
	}
	else
		return ;
}

void	ft_read_lst(t_data *data)
{
	char	***cmd_tab;

	cmd_tab = creat_tab(data);
	data->pipe = count_pipe(data);
	if (data->pipe > 0 && data->cmd->pipe == true)
	{
		execute_pipeline(data, cmd_tab);
	}
	else if ((data->infile || data->outfile))
	{
		check_redir(data, cmd_tab);
	}
	else if (cmd_tab[1] == NULL && !data->outfile)
	{
		ft_launch(data, cmd_tab[0]);
	}
	ft_reset_std(data);
	free_tab(cmd_tab);
}

static void	create_tab_help(t_cmd **current, char ***cmd_tab, int *j, int *i)
{
	cmd_tab[*i] = malloc((count_cmd((*current)) + 1) * sizeof(char *));
	if (!cmd_tab[*i])
		return ;
	while (*current && (*current)->type >= 0 && (*current)->type <= 2)
	{
		cmd_tab[*i][*j] = ft_shelldup((*current)->str);
		*current = (*current)->next;
		(*j)++;
	}
	cmd_tab[*i][*j] = NULL;
	*j = 0;
	(*i)++;
	return ;
}

char	***creat_tab(t_data *data)
{
	int		i;
	int		j;
	int		size;
	char	***cmd_tab;
	t_cmd	*current;

	i = 0;
	j = 0;
	size = lst_cmd_size(data);
	cmd_tab = malloc((size + 1) * sizeof(char **));
	if (!cmd_tab)
		return (NULL);
	current = data->cmd;
	while (current)
	{
		if (current->type >= 0 && current->type <= 2)
			create_tab_help(&current, cmd_tab, &j, &i);
		else
			current = current->next;
	}
	cmd_tab[i] = NULL;
	return (cmd_tab);
}
