NAME	= libft.a
INCLUDE = ./include/
CFLAGS	+= -Wall -Werror -Wextra

FILES	=

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
