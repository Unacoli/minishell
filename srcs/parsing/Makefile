#MAKEFLAGS = --silent

CC =		cc

CFLAGS =	-Wall -Wextra -Werror
FSAN =		-g -fsanitize=address

IFLAGS = 	-I ../../include -I ../../libft/include

NAME = 		parsing

RM =		rm -rf

HEADER = 	../../include/minishell.h

OBJS_PATH = objs/

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m
_END= 	$'\033[37m

SRC =	double_lexer.c \
		fill_lexer.c \
		get_token.c \
		handle_quote_substi.c \
		lexer.c \
		parsing.c \
		token.c \
		utils.c
OBJ = $(addprefix $(OBJS_PATH), $(SRC:.c=.o))

$(OBJS_PATH)%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS)  $(IFLAGS) -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	

$(NAME): 	$(OBJ) $(HEADER) libft
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) libft.a -o ${NAME}
	@printf "\n${_GREEN}${_BOLD}[Parsing OK]${_END}\n"
	
all: $(NAME)

test:		$(OBJ) $(HEADER) libft
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(CFLAGS) $(FSAN) $(IFLAGS) $(OBJ) -o ${NAME}
	@printf "\n${_GREEN}${_BOLD}[Parsing fsanitize OK]${_END}\n"

libft:
	@make -C ../../libft/
	@mv ../../libft/libft.a ./

clean:
	@$(RM) $(OBJS_PATH) 

fclean:		clean
	@$(RM) $(NAME)  libft.a pipex_bonus

re: fclean all

.PHONY: 	clean fclean re all libft