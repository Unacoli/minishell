# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:14:59 by nargouse          #+#    #+#              #
#    Updated: 2022/05/11 17:16:38 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
INCLUDE = ./include/
LIBFT	= ./libft/libft.a
CFLAGS	+= -Wall -Werror -Wextra -g3

FILES	= main.c pwd.c util.c echo.c exitfree.c norm.c autres.c fi.c

SRCS	= $(addprefix ./srcs/, $(FILES))
OBJS	= $(addprefix ./objs/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $@ -lreadline

objs/%.o: srcs/%.c
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
