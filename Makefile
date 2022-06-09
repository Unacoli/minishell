# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 14:18:39 by ldubuche          #+#    #+#              #
#    Updated: 2022/06/09 15:06:58 by ldubuche         ###   ########.fr        #
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
			srcs/exiting/free_ast.c \
			srcs/exiting/free_cmd.c \
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

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $@ -lreadline
	@printf "\n${_GREEN}${_BOLD}[Minishell OK]${_END}\n"

$(OBJS_PATH)%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft
