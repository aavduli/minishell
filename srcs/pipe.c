/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:01:05 by aavduli           #+#    #+#             */
/*   Updated: 2024/06/05 11:12:10 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_cmd(t_cmd *cmd, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	safe_pipe(pipefd);
	pid = fork();
	safe_pid(pid);
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execute(cmd->cmd, envp);
	}
	else
	{
		waitpid(pid, &g_data.exit_status, 0);
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
}

