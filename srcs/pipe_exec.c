/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:27:13 by albertini         #+#    #+#             */
/*   Updated: 2024/08/05 19:58:02 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	init_pipes(t_data *data, int i, int pipefd[2], int *out)
{
	if (i < data->pipe)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		*out = pipefd[1];
	}
	else
	{
		if (data->outfile)
			*out = ft_stdout_inpipe(data);
		else
			*out = STDOUT_FILENO;
	}
}

static void	execute_single_command(t_data *data, char **cmd, int in, int out)
{
	execute_pipe(data, cmd, in, out);
	if (in != STDIN_FILENO)
		close(in);
	if (out != STDOUT_FILENO)
		close(out);
}

void	execute_pipeline(t_data *data, char ***cmd_tab)
{
	int		i;
	int		pipefd[2];
	int		in;
	int		out;

	i = 0;
	in = ft_stdin_inpipe(data);
	out = STDOUT_FILENO;
	while (i < data->pipe + 1)
	{
		init_pipes(data, i, pipefd, &out);
		execute_single_command(data, cmd_tab[i], in, out);
		in = pipefd[0];
		i++;
	}
	if (in != STDIN_FILENO)
		close(in);
	while (wait(NULL) > 0)
		;
	ft_reset_std(data);
}
