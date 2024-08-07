/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:46:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/08/07 13:29:12 by falberti         ###   ########.fr       */
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
# include <stdbool.h>
# include <stdbool.h>

/*
 0 = CMD
 1 = CMD_S_QUOTE
 2 = CMD_D_QUOTE
 3 = CMD_PIPE
 4 = CMD_IN_RED
 5 = CMD_OUT_RED
 6 = CMD_APP_OUT_RED
 7 = CMD_ENV_VAR
 8 = CMD_LAST_EXIT
 9 = CMD_HEREDOC
 10 = CMD_ERROR
 11 = CMD_FILE
*/

enum e_cmdtype
{
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
	CMD_ERROR,
	CMD_FILE
};

typedef struct s_cmd	t_cmd;

struct s_cmd
{
	char			*str;
	int				type;
	bool			pipe;
	t_cmd			*next;
	t_cmd			*prev;
};

typedef struct s_data
{
	t_cmd	*cmd;
	char	*nprompt;
	int		exit_status;
	char	**env;
	char	**original;
	char	*infile;
	char	*outfile;
	int		stdin;
	int		stdout;
	int		pipe;
	int		out;
	bool	output;
}	t_data;

//init_structs
void	init_cmd(t_cmd *c);
void	init_data(t_data *d);

//signal
void	run_signal(int sig);

// parsing
void	get_input(t_data *data);

//pars_utils
int		get_nb_strs(char **strs);
char	**ft_cpy_env(char **strs);
void	check_update_type(t_data *data);

//pars_check
int		is_valid_type(const char *str);
int		determine_type(const char *str);

//pars_split
int		ischar(char c);
char	**mini_split(char const *s);

//pars_nodes_cre
void	split_create_cmd_list(t_data *data, char *input);
//void	print_split(char **split);

//heredoc
void	execute_command_with_heredoc(char **com, char *del, int var, t_data *d);

//heredoc_utils
char	*ft_strtok(char *str, const char *delim);

//Variables
char	*replace_env_variables(char *input, t_data *data);
int		get_full_size(char *str, t_data *data);

//Var_utils
char	*get_env(char *name, t_data *data);
char	*get_env_value(char *var, t_data *data);
char	*extract_variable_name(char *start);
char	*ft_strndup(const char *s, size_t n);
void	count_exit(int *nb, char **str, t_data *data);

//Builtins
void	ft_str_exit(char *str, int exit, t_data *data);
void	ft_env(t_data *data);
void	ft_cd(char **cmd, t_data *data);
void	ft_pwd(char **cmd, t_data *d);
void	ft_echo(char **cmd, t_data *d);
void	ft_cmd(char **cmd, t_data *data);
void	ft_export(char **cmd, t_data *data);
void	ft_unset(char **cmd, t_data *data);
void	ft_mshell(t_data *data, char **cmd);

//Exec
char	***creat_tab(t_data *data);
void	ft_execute(char **cmd, t_data *data);
void	ft_launch(t_data *data, char **cmd);
char	*find_path(char *cmd, char **envp);

//safe_functions
void	ft_reset_std(t_data *data);
void	*safe_malloc(size_t bytes);
pid_t	safe_pid(pid_t pid);
void	safe_pipe(int pipefd[2]);

//freerers
void	free_list(char **list);
void	free_cmd(t_cmd *head);
void	free_all(t_data *data);
void	free_tab(char ***tab);

//lst_utils
//t_cmd	*create_new_node(char *str);
void	ft_read_lst(t_data *data);
int		lst_cmd_size(t_data *data);
int		count_pipe(t_data *data);
int		count_cmd(t_cmd *current);

//redirection
void	check_redir(t_data *data, char ***cmd);
void	ft_reset_std(t_data *data);
void	ft_stdin(t_data *data);
void	ft_stdout(t_data *data);
int		ft_stdin_inpipe(t_data *data);
int		ft_stdout_inpipe(t_data *data);

void	execute_pipe(t_data *data, char **cmd, int in, int out);
void	execute_pipeline(t_data *data, char ***cmd_tab);

//exit
int		is_exit(char *str, t_data *data);

#endif
