/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:57:39 by avdylavduli       #+#    #+#             */
/*   Updated: 2024/06/20 15:02:52 by albertini        ###   ########.fr       */
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

//types
//-1. Init
// 0. NULL
// 1. cmd
// 2. args
// 3. str
// 4. str_null
// 5. pipe
// 6. redi
// 7. extra


typedef struct s_cmd	t_cmd;

struct s_cmd
{
	char			*str;
	int				type;
	//char			**args;
	t_cmd			*next;
	t_cmd			*prev;
};

typedef struct s_data
{
	t_cmd	*cmd;
	char	*full_str;
	char	*nprompt;
	int		exit_status;
	char	**env;
	char	**original;
}	t_data;

//signal
void	run_signal(int sig);

//init_structs
void	init_cmd(t_cmd *c);
void	init_data(t_data *d);

//exit
int		is_exit(char *str);

//parsing
void	get_input(t_data *data);

//utils_pars
int		get_nb_strs(char **strs);
char	**ft_cpy_env(char **strs);

//builtins
void	ft_pwd(t_data *data);
void	ft_cmd(char *str, t_data *data);

//Exec
void	execute(char *str, t_data data);

//command
void	ft_split_cmd(t_data *d);

//type_checker
int		type_check(t_cmd cmd);

//split_cmd
t_cmd	**create_cmd(t_data d);

//freerer
void	free_split(char **list);

#endif
