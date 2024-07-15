/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:57:39 by avdylavduli       #+#    #+#             */
/*   Updated: 2024/07/15 13:49:10 by aavduli          ###   ########.fr       */
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

/*
 1 = CMD
 2 = CMD_S_QUOTE
 3 = CMD_D_QUOTE
 4 = CMD_PIPE
 5 = CMD_IN_RED
 6 = CMD_OUT_RED
 7 = CMD_APP_OUT_RED
 8 = CMD_ENV_VAR
 9 = CMD_LAST_EXIT
 10 = CMD_HEREDOC
 11 = CMD_ERROR
*/

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

//Builtins
void	ft_env(t_data *data);
void	ft_cd(char **cmd, t_data *data);
void	ft_pwd(char **cmd);
void	ft_echo(char **cmd);
void	ft_cmd(char **cmd, t_data *data);
void	ft_export(char **cmd, t_data *data);
void	ft_unset(char **cmd, t_data *data);
void	ft_mshell(t_data *data, char **cmd);

//Exec
void	ft_read_cmd(t_data *data);
void	ft_execute(char **cmd, t_data *data);

//safe_functions
void	*safe_malloc(size_t bytes);
void	*safe_pid(pid_t pid);

//freerers
void	free_list(char **list);
void	free_cmd(t_cmd *head);
void	free_all(t_data *data);
void	free_tab(char **tab);

//lst_utils
int		lst_cmd_size(t_data *data);

//exit
int		is_exit(char *str, t_data *data);

#endif
