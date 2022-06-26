# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 22:47:57 by nargouse          #+#    #+#              #
#    Updated: 2022/06/26 19:23:54 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
INCLUDE = ./include/
LIBFT	= ./libft/libft.a
CFLAGS	+= -Wall -Werror -Wextra -g3

DEPS	= ./libft/include/libft.h ./include/ Makefile

FILES	= main.c start_shell.c ast.c parse_command.c simple_command.c\
			cd.c echo.c env.c exit.c export.c pwd.c unset.c utils.c\
			default_env.c environnement.c built-in.c execve.c here_doc.c\
			input_file.c output_file.c pipex.c substitution.c error.c\
			exit_shell.c free_env.c free_lexer.c command.c input.c\
			signal_handler.c double_lexer.c handle_quote_substi.c\
			malloc_token.c parsing.c utils2.c get_token.c handle_token.c\
			malloc_lexer.c old_function.c tokenize.c io_file.c command_suffix.c

SRCS	= $(addprefix ./srcs/*/, $(FILES))
OBJS	= $(addprefix ./objs/, $(MAIN:.c=.o) $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $@ -lreadline

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
