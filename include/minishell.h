/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:00:27 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/11 16:51:58 by ldubuche         ###   ########.fr       */
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

typedef struct s_ctrl
{
	t_lexer	*lexer;
	t_ast	*ast;
	t_cmd	*cmd;
}				t_ctrl;

/*Functions for lexer*/

void	create_lexer(t_lexer *lexer, size_t cap);
t_lexer	*malloc_lexer(size_t cap);
int		lexer_full(t_lexer *lexer);
int		pass(t_lexer *lexer, t_ttype needed);
void	add_token_to_lexer(t_lexer *lexer, const char *s, size_t len,
			t_ttype type);
void	add_word_to_lexer(t_lexer *lexer, char **token_s);
void	double_lexer(t_lexer *lexer);
void	handle_token(t_lexer *lexer, t_regex token);

/*Functions for tokens*/

t_token	create_token(const char *str, size_t len, t_ttype type);
t_token	*malloc_token(const char *s, size_t len, t_ttype type);
int		tokenize(t_lexer *lexer);
t_regex	get_token(char *input, t_lexer *lexer);
void	get_next_token(t_lexer *lexer);
int		push_char(t_lexer *lexer, char **token_s);
t_regex	handle_quote(char *input, t_lexer *lexer, char c);
char	*create_str(char *input, int i);
t_regex	handle_substitution(char *input);
int		is_space(char c);

/*Functions for main, starting minishell*/

void	init_shell(t_ctrl minishell);
void	choose_env(char **env);
int		running_shell(t_ctrl minishell);

/*Old functions, WIP to sort this*/

typedef struct s_env	t_env;
void	parsing(char *cmd, t_env *enviro);
void	ctrlc(int i);
char	*pwd(void);
char	*envi( t_env *enviro);
char	*ft_strjoinchar(char const *s1, char const s2);
t_env	*initenv(char **env);
char	*export(char *cmd, t_env *un);
void	changedeb(t_env *un);
void	unset(char *cmd, t_env *un);
char	*cd(char	*cmd, t_env	*envi);
char	*echo(char	*cmd, t_env *enviro, int tiretn);
char	*getvale(char *name, t_env *un);
void	lexe(char *cmd, t_env *envi);
void	exitfree(t_env *un);
void	freeenv(t_env *un);
int		checkname(char *name);
void	exed(char *cmd, t_env *envi);
char	**getenvchar(t_env *enviro);
void	freetr(char	**pa, char *name, int i);
char	*getna(char *cmd);
void	child(char *path, char **argv, char**env, char *name);
void	coredump(int sig);
void	childctrlc(int sig);
void	freetab(char **tab);
void	addele(t_env *un, char **retsplit);
char	*exportun(t_env *un);
char	*exportd(char *cmd, t_env *un);

/* je crois qu'il manque le typedef t_env */
struct s_env
{
	t_env	*deb;
	int		haveeq;
	char	*name;
	char	*value;
	t_env	*next;
};

#endif
