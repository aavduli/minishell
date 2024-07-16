/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:01:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/07/16 15:43:34 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	connect_pipe(infile, outfile)
{
	pid_t	pid;
	int		status;

	pid = fork();
	safe_pid(pid);
	if (pid == 0)
	{
		if (dup2(infile, STDIN_FILENO) == -1)
			perror("Dup2 failed");
		if (dup2(outfile, STDOUT_FILENO) == -1)
			perror("Dup2 failed");
		if (infile != STDIN_FILENO)
			close(infile);
		if (outfile != STDOUT_FILENO)
			close(outfile);
	}
	else
		waitpid(pid, &status, 0);
	return ;
}

void	pipe(t_data data)
{
	int	pipefd[2];
	int	in;

	safe_pipe(pipefd);
	if (data->infile)
		in = open(data->infile, O_RDONLY);
	else
		in = STDIN_FILENO;
	connect_pipe(in, pipefd[1]);
	close(pipefd[1]);
	if (in != STDIN_FILENO)
		close(in);
	in = pipefd[0];
	if (data->outfile)
		data->outfile = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		data->outfile = STDOUT_FILENO;
}
/*
void	mutli_pipe(int infile, int outfile, char **av, char **envp)
{
	int	i;
	int	fd[2];
	int	in;

	i = 2;
	in = infile;
	while (av[i + 2] != NULL)
	{
		if (pipe(fd) == -1)
			error();
		connect_pipe(in, fd[1], av[i], envp);
		close(fd[1]);
		if (in != infile)
			close(in);
		in = fd[0];
		i++;
	}
	if (in != infile)
		dup2(in, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	if (in != infile)
		close(in);
	execute(av[i], envp);
	close(outfile);
}
*/
