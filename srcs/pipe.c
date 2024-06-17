/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:01:05 by aavduli           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/19 11:32:26 by aavduli          ###   ########.fr       */
=======
/*   Updated: 2024/06/17 15:54:47 by aavduli          ###   ########.fr       */
>>>>>>> 92d760b (pipe & execute)
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	connect_pipe(int infile, int outfile, char *cmd, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	safe_pid(pid);
	if (pid == 0)
	{
		if (dup2(infile, STDIN_FILENO) == -1)
			error_exit("Dup2 failed");
		if (dup2(outfile, STDOUT_FILENO) == -1)
			error_exit("Dup2 failed");
		if (infile != STDIN_FILENO)
			close(infile);
		if (outfile != STDOUT_FILENO)
			close(outfile);
		execute(cmd, envp);
	}
	else
		waitpid(pid, &status, 0);
}

<<<<<<< HEAD

=======
void	multi_pipe(int infile, int outfile, char **av, char **envp)
{
	int	i;
	int	pipefd[2];
	int	in;

	i = 2;
	in = infile;
	while (av[i + 2] != NULL)
	{
		safe_pipe(pipefd);
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
>>>>>>> 92d760b (pipe & execute)
