# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 14:54:05 by nargouse          #+#    #+#              #
#    Updated: 2022/03/02 15:04:57 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
INCLUDE = ./include/
CFLAGS	+= -Wall -Werror -Wextra

FILES	= ft_atoi.c ft_lstsize.c ft_strlcat.c ft_bzero.c ft_memccpy.c\
		ft_strlcpy.c ft_calloc.c ft_memchr.c ft_strlen.c ft_free.c\
		ft_memcmp.c ft_strmapi.c ft_isalnum.c ft_memcpy.c ft_strncmp.c\
		ft_isalpha.c ft_memmove.c ft_strndup.c ft_memset.c\
		ft_strnjoin_free.c ft_isascii.c ft_putchar_fd.c ft_strnstr.c\
		ft_isdigit.c ft_putendl_fd.c ft_strrchr.c ft_isprint.c\
		ft_putnbr.c ft_strtrim.c ft_itoa.c ft_putnbr_fd.c ft_substr.c\
		ft_lstadd_back.c ft_putstr.c ft_tolower.c ft_lstadd_front.c\
		ft_putstr_fd.c ft_toupper.c ft_lstclear.c ft_split.c\
		get_next_line.c ft_lstdelone.c ft_strchr.c ft_lstiter.c\
		ft_strdup.c ft_lstlast.c ft_strichr.c ft_lstmap.c ft_strjoin.c\
		ft_lstnew.c ft_strjoin_free.c ft_int_error.c ft_flag_c.c\
        ft_flag_diu.c ft_flag_p.c ft_flag_pourcent.c ft_flag_s.c ft_flag_x.c\
        ft_printf.c ft_quit.c ft_print_str_tab.c ft_free_tab.c

SRCS    = $(addprefix ./srcs/, $(FILES))
OBJS	= $(addprefix ./objs/, $(FILES:.c=.o))

all:	$(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo $(NAME)

objs/%.o: srcs/%.c
	@mkdir -p ./objs/
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
