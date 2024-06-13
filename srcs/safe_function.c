/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:20:10 by avdylavduli       #+#    #+#             */
/*   Updated: 2024/06/13 14:22:52 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	safe_malloc(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
	{
		printf("Malloc failed\n");
		exit(1);
	}
}

void	error_exit(const char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	safe_pid(pid_t pid)
{
	if (pid < 0)
		error_exit("Fork failed");
}

void	safe_pipe(int *pipefd)
{
	if (pipe(pipefd) == -1)
		error_exit("Pipe failed");
}
