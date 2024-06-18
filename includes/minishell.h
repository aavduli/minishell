/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:57:39 by avdylavduli       #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2024/06/19 11:30:55 by aavduli          ###   ########.fr       */
=======
/*   Updated: 2024/06/11 10:23:00 by aavduli          ###   ########.fr       */
>>>>>>> 8fc4d0d (little update)
=======
/*   Updated: 2024/06/17 13:05:30 by aavduli          ###   ########.fr       */
>>>>>>> 86d0a32 (updated my branch)
=======
/*   Updated: 2024/06/17 16:07:12 by aavduli          ###   ########.fr       */
>>>>>>> 92d760b (pipe & execute)
/*   Updated: 2024/06/18 16:22:20 by aavduli          ###   ########.fr       */
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


typedef struct s_cmd
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
	char	*str;
	char	*nprompt;
	char	**env;
	int		exit_status;
	char	**env;
	char	**original;
}	t_data;

//signal
void	run_signal(int sig);

//init_structs
void	init_cmd(t_cmd *c);
void	init_data(t_data *d);

//pipe
void	multi_pipe(int infile, int outfile, char **av, char **envp);

//path
char	*find_path(char *cmd, char **envp);

//builtins
void	ft_pwd(t_data data);
<<<<<<< HEAD
//exit
int		is_exit(char *str);
=======
//pipe
void	multi_pipe(int infile, int outfile, char **av, char **envp);
void	execute(char *av, char **envp);

//execute
void	execute(t_data data);


>>>>>>> 92d760b (pipe & execute)

<<<<<<< HEAD
//parsing
void	get_input(t_data *data);

//execute
void	ft_cmd(t_data data);
void	execute(t_data data);


//Exit
int   is_exit(char *str);

=======
>>>>>>> 86d0a32 (updated my branch)
#endif

