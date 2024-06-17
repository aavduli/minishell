/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:20:10 by avdylavduli       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/19 11:32:41 by aavduli          ###   ########.fr       */
=======
/*   Updated: 2024/06/17 13:25:35 by aavduli          ###   ########.fr       */
>>>>>>> 92d760b (pipe & execute)
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
