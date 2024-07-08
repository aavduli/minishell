/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:57:39 by avdylavduli       #+#    #+#             */
/*   Updated: 2024/07/08 15:44:00 by falberti         ###   ########.fr       */
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
	char			**args;
	t_cmd			*next;
	t_cmd			*prev;
};

typedef struct s_data
{
	t_cmd	*cmd;
	char	**str;
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
int		check_str_type(char *str);

// //Builtins
// void	ft_env(t_data *data);
// void	ft_cd(t_data *data);
// void	ft_pwd(t_data *data);
// void	ft_echo(t_data *data);
// void	ft_cmd(t_data *data);
// void	ft_export(t_data *data);
// void	ft_unset(t_data *data);

//Exec
void	ft_execute(t_data *data);

//safe_functions
void	safe_pid(pid_t pid);

//Mini Split
char	**mini_split(char const *s);

//freerers
void	free_list(char **list);

// //Command
// void	ft_echo(t_data *data);
// void	ft_pwd(t_data *data);
// void	ft_cmd(t_data *data);


#endif
