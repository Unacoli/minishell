/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:00:27 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/13 10:44:31 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/include/libft.h"
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>

# define MAX_TOKENS 12
# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34

/*Environnement global*/

extern char	**g_env;

/*Enum definition for token and ast*/

typedef enum e_ttype
{
	TOKEN_NOT_VALID = 0,
	TOKEN_PASS,
	TOKEN_PIPE,
	TOKEN_LESS,
	TOKEN_GREAT,
	TOKEN_DGREAT,
	TOKEN_DLESS,
	TOKEN_NEWLINE,
	TOKEN_WORD,
}				t_ttype;

typedef enum e_node
{
	NODE_PROGRAM = 0,
	NODE_CMD,
	NODE_CMD_SUFFIX,
	NODE_IO_FILE,
	NODE_PIPE_SEQ,
	NODE_SIMPLE_CMD,
	NODE_WORD,
}				t_node;

/*Structs for parsing and ast*/

typedef struct s_regex
{
	const char	*op;
	size_t		len;
	t_ttype		type;
}				t_regex;

typedef struct s_token
{
	char	*str;
	size_t	len;
	t_ttype	type;
}				t_token;

typedef struct s_lexer
{
	size_t	pos;
	size_t	size;
	size_t	capacity;
	char	*input;
	t_token	**tokens;
}				t_lexer;

typedef struct s_ast
{
	t_node			type;
	struct s_ast	*left;
	struct s_ast	*right;
	char			*data;
}				t_ast;

/*Structs for execution*/

typedef struct s_simplecmd
{
	size_t	ac;
	char	**av;
	char	*input_file;
	char	*output_file;
}				t_simplecmd;

typedef struct s_cmd
{
	size_t		cap;
	size_t		cmd_count;
	t_simplecmd	**simple_cmd;
}				t_cmd;

/*Struct for controller*/

typedef struct s_ctrl
{
	t_lexer	*lexer;
	t_ast	*ast;
	t_cmd	*cmd;
}				t_ctrl;

/*Functions for lexer*/

void	create_lexer(t_lexer *lexer, size_t cap);
t_lexer	*malloc_lexer(size_t cap);
void	handle_token(t_lexer *lexer, t_regex token);
void	add_token_to_lexer(t_lexer *lexer, const char *s, size_t len,
			t_ttype type);
void	double_lexer(t_lexer *lexer);
// int		pass(t_lexer *lexer, t_ttype needed);
// void	add_word_to_lexer(t_lexer *lexer, char **token_s);

/*Functions for tokens*/

t_token	create_token(const char *str, size_t len, t_ttype type);
t_token	*malloc_token(const char *s, size_t len, t_ttype type);
int		tokenize(t_lexer *lexer);
t_regex	get_token(char *input, t_lexer *lexer);
t_regex	handle_quote(char *input, t_lexer *lexer, char c);
t_regex	handle_substitution(char *input);
// void	get_next_token(t_lexer *lexer);
// int		push_char(t_lexer *lexer, char **token_s);

/* Utils parsing */
int		is_space(char c);
char	*create_str(char *input, int i);
int		is_operator(char *input);
int		delimite_word(char *input, int i);

/* Free function */

void	free_lexer(t_lexer *lexer);

/*Functions for main, starting minishell*/

void	init_shell(t_ctrl minishell);
void	choose_env(char **env);
int		running_shell(t_ctrl *minishell);

/*Functions for input processing*/

void	input(t_ctrl *minishell);

/*Signal handler*/

void	signal_handler(void);
void	error(int signal);

typedef struct s_env
{
	struct s_env	*deb;
	int				haveeq;
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

/* Function for Built-In */
char	*pwd(void);
char	*envi( t_env *enviro);
char	*ft_strjoinchar(char const *s1, char const s2);
char	*export(char *cmd, t_env *un);
void	changedeb(t_env *un);
void	unset(char *cmd, t_env *un);
char	*cd(char	*cmd, t_env	*envi);
char	*echo(char	*cmd, t_env *enviro, int tiretn);
char	*getvale(char *name, t_env *un);
int		checkname(char *name);
char	*exportun(t_env *un);
char	*exportd(char *cmd, t_env *un);
void	exitfree(t_env *un);

/*Old functions, WIP to sort this*/

void	lexe(char *cmd, t_env *envi);
void	freeenv(t_env *un);
void	exed(char *cmd, t_env *envi);
char	**getenvchar(t_env *enviro);
void	freetr(char	**pa, char *name, int i);
char	*getna(char *cmd);
void	child(char *path, char **argv, char**env, char *name);
void	coredump(int sig);
void	childctrlc(int sig);
void	freetab(char **tab);
void	addele(t_env *un, char **retsplit);	

#endif
