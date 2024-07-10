# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falberti <falberti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 12:52:36 by falberti          #+#    #+#              #
#    Updated: 2024/07/10 13:31:01 by falberti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Sources
SOURCES_DIR = srcs
LIBRARIES_DIR = includes

HEADER = $(LIBRARIES_DIR)/minishell

FILES = $(SOURCES_DIR)/minishell\
        $(SOURCES_DIR)/signals\
        $(SOURCES_DIR)/init_structs\
        $(SOURCES_DIR)/exit\
        $(SOURCES_DIR)/parsing\
        $(SOURCES_DIR)/pars_utils\
		$(SOURCES_DIR)/exec\
        $(SOURCES_DIR)/commands\
		$(SOURCES_DIR)/freerers\
		$(SOURCES_DIR)/pars_split\
		$(SOURCES_DIR)/pars_check\

## Ajout de .c et .o aux fichiers dans FILES
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))

####################################################################
## Varguments
CC = gcc
CFLAGS = -Werror -Wextra -Wall -I $(HEADER) -I/opt/homebrew/opt/readline/include -g
LDFLAGS = -L/opt/homebrew/opt/readline/lib -lreadline -lhistory
NAME = mshell

#####################################################################
## Rules

LIBFTXL = includes/libft_xl/libftxl.a

all: $(NAME)

$(LIBFTXL):
	$(MAKE) -C includes/libft_xl

## -fsanitize=address
$(NAME): $(OFILES) $(LIBFTXL)
	$(CC) $(OFILES) $(LIBFTXL) $(LDFLAGS) -o $(NAME)

### For each .o file it needs the .c file | $< is automatic var that takes the param and $@ the target
$(SOURCES_DIR)/%.o: $(SOURCES_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C includes/libft_xl clean
	rm -f $(OFILES)

fclean: clean
	$(MAKE) -C includes/libft_xl fclean
	rm -f $(NAME)

re: fclean all
