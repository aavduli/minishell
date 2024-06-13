/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:57:39 by avdylavduli       #+#    #+#             */
/*   Updated: 2024/06/13 13:15:46 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft_xl/libft.h"

//TODO : maybe we need to add more struc, or enum or smth else.

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	int				pipe;
	int				redir;
	int				redir_type;
	char			*redir_file;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_env	*env;
	t_cmd	*cmd;
  char  *str;
	int		exit_status;
}	t_data;

//Signal
void	run_signal(int sig);

//init_data
void	init_data(t_data *d);


#endif