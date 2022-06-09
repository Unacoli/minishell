# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:14:59 by nargouse          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/06/03 15:04:15 by ldubuche         ###   ########.fr        #
=======
#    Updated: 2022/06/09 04:10:22 by nargouse         ###   ########.fr        #
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880
#                                                                              #
# **************************************************************************** #

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m
_END= 	$'\033[37m

<<<<<<< HEAD
CC		= 	cc
NAME	= 	minishell
INCLUDE = 	./include/
LIBFT	= 	./libft/libft.a
CFLAGS	= 	-Wall -Werror -Wextra -g3
HEADER	= 	include/minishell.h \
			include/ast.h \
			include/built_in.h \
			include/controller.h \
			include/environnement.h \
			include/execution.h \
			include/handle_input.h \
			include/parsing.h

SRCS	= 	srcs/main.c \
			srcs/start_shell.c \
			srcs/environnement/environnement.c \
			srcs/environnement/default_env.c \
			srcs/built-in/exit.c \
			srcs/built-in/pwd.c \
			srcs/built-in/env.c \
			srcs/exiting/error.c \
			srcs/exiting/free_lexer.c \
			srcs/exiting/free_env.c \
			srcs/exiting/exit_shell.c \
			srcs/handle_input/input.c \
			srcs/handle_input/signal_handler.c \
			srcs/handle_input/command.c \
			srcs/parsing/malloc_lexer.c \
			srcs/parsing/double_lexer.c \
			srcs/parsing/get_token.c \
			srcs/parsing/handle_quote_substi.c \
			srcs/parsing/malloc_token.c \
			srcs/parsing/handle_token.c \
			srcs/parsing/tokenize.c \
			srcs/parsing/utils.c

OBJS_PATH = ./objs/
OBJS	= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
=======
FILES	= main.c start_shell.c ast.c parse_command.c simple_command.c\
			cd.c echo.c env.c exit.c export.c pwd.c unset.c utils.c\
			default_env.c environnement.c built-in.c execve.c here_doc.c\
			input_file.c output_file.c pipex.c substitution.c error.c\
			exit_shell.c free_env.c free_lexer.c command.c input.c\
			signal_handler.c double_lexer.c handle_quote_substi.c\
			malloc_token.c parsing.c utils2.c get_token.c handle_token.c\
			malloc_lexer.c old_function.c tokenize.c io_file.c

SRCS	= $(addprefix ./srcs/*/, $(FILES))
OBJS	= $(addprefix ./objs/, $(FILES:.c=.o))
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $@ -lreadline
	@printf "\n${_GREEN}${_BOLD}[Minishell OK]${_END}\n"

<<<<<<< HEAD
$(OBJS_PATH)%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	
=======
objs/%.o: srcs/*/%.c
	mkdir -p ./objs/
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS) 

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re:	fclean all

.PHONY:	all clean fclean re
