/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:57:39 by avdylavduli       #+#    #+#             */
/*   Updated: 2024/07/10 17:04:34 by falberti         ###   ########.fr       */
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

enum e_cmdtype {
	CMD_NONE,
	CMD_S_QUOTE,
	CMD_D_QUOTE,
	CMD_PIPE,
	CMD_IN_RED,
	CMD_OUT_RED,
	CMD_APP_OUT_RED,
	CMD_ENV_VAR,
	CMD_LAST_EXIT,
	CMD_HEREDOC,
	CMD_ERROR
};

typedef struct s_cmd	t_cmd;

struct s_cmd
{
	char			*str;
	int				type;
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

//init_structs
void	init_cmd(t_cmd *c);
void	init_data(t_data *d);

//signal
void	run_signal(int sig);

//parsing
void	get_input(t_data *data);

//pars_utils
int		get_nb_strs(char **strs);
char	**ft_cpy_env(char **strs);
void	check_update_type(t_data *data);

//pars_check
int		is_valid_type(const char *str);
int		determine_type(const char *str);

//pars_split
char	**mini_split(char const *s);
//void	print_split(char **split);

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

//freerers
void	free_list(char **list);
void	free_cmd(t_cmd *head);
void	free_all(t_data *data);

//exit
int		is_exit(char *str, t_data *data);

// //Command
// void	ft_echo(t_data *data);
// void	ft_pwd(t_data *data);
// void	ft_cmd(t_data *data);

#endif
