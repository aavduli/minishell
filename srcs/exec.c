/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:30:27 by aavduli           #+#    #+#             */
/*   Updated: 2024/06/05 11:31:06 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_cmd *cmd, char **envp)
{
	pid_t	pid;
	char	*path;

	pid = fork();
	safe_pid(pid);
	if (pid == 0)
	{
		if (cmd->pipe)
			pipe_cmd(cmd, envp);
		else
		{
			if (cmd->redir)
				redir_cmd(cmd);
			else
			{
				path = find_path(cmd->cmd, envp);
				if (!path)
					error_exit("Command not found");
				execve(path, cmd->args, envp);
			}
		}
	}
	else
		waitpid(pid, &g_data.exit_status, 0);
}
