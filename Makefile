# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 22:47:57 by nargouse          #+#    #+#              #
#    Updated: 2022/07/10 17:56:17 by ldubuche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
INCLUDE = ./include/
LIBFT	= ./libft/libft.a
CFLAGS	+= -Wall -Werror -Wextra -g3

DEPS	= ./libft/include/libft.h ./include/ Makefile

FILES	= main.c start_shell.c cd.c echo.c env.c exit.c export.c pwd.c unset.c\
			utils.c default_env.c environnement.c built_in.c simple_execve.c\
			here_doc.c input_file.c output_file.c pipex.c substitution.c\
			error.c exit_shell.c free_env.c free_lexer.c command.c input.c\
			signal_handler.c double_lexer.c handle_quote_substi.c\
			malloc_token.c utils_parsing.c get_token.c handle_token.c\
			malloc_lexer.c tokenize.c simple_cmd.c malloc_cmd.c free_cmd.c\
			treat_token.c execution.c

SRCS	= $(addprefix ./srcs/*/, $(FILES))
OBJS	= $(addprefix ./objs/, $(MAIN:.c=.o) $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $@ -lreadline -ltinfo

objs/%.o: srcs/*/%.c $(DEPS)
	mkdir -p ./objs/
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

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
