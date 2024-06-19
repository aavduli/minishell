# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 12:52:36 by falberti          #+#    #+#              #
#    Updated: 2024/06/19 13:56:35 by aavduli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
SOURCES_DIR		=	srcs
lIBRARIES_DIR	=	includes

HEADER = $(lIBRARIES_DIR)/minishell

FILES = $(SOURCES_DIR)/minishell\
				$(SOURCES_DIR)/signals\
				$(SOURCES_DIR)/init_structs\
				$(SOURCES_DIR)/exit\
				$(SOURCES_DIR)/parsing\
				$(SOURCES_DIR)/utils_pars\
				$(SOURCES_DIR)/builtins\

## This is a bit tricky for me but it ask to check the end of the string in FILES than add .c if there is nothing
## Also possible to just liste the .c and .o files
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))

####################################################################
## Varguments
CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER)  -g
NAME = mshell

#####################################################################
## Rules

LIBFTXL = includes/libft_xl/libftxl.a

##all: FLAGS = $(CFLAGS)
all: $(NAME)

$(LIBFTXL):
	$(MAKE) -C includes/libft_xl

## -fsanitize=address
$(NAME): $(OFILES) $(LIBFTXL)
		$(CC) $(OFILES) $(LIBFTXL) -lreadline -o $(NAME)

### For each .o file  it needs the .c file | $< is automatic var that takes the param and $@ the target
$(FILES).o: $(FILES).c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) -C includes/libft_xl clean
		rm -f $(OFILES)

fclean: clean
		$(MAKE) -C includes/libft_xl fclean
		rm -f $(NAME)

re: fclean clean all
