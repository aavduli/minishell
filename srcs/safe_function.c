/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:20:10 by avdylavduli       #+#    #+#             */
/*   Updated: 2024/07/22 17:34:18 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*safe_malloc(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
		printf("Malloc failed\n");
	return (ptr);
}

void	error_exit(const char *msg)
{
	printf("%s\n", msg);
	return ;
}

pid_t	safe_pid(pid_t pid)
{
	if (pid < 0)
		printf("Fork failed\n");
	return (pid);
}

void	safe_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		printf("Pipe failed\n");
}
