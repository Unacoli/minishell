/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:37:10 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 16:47:02 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define MAX_TOKENS 12
# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34
# define BACK_SLASH 92

# include "environnement.h"
# include "execution.h"

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

/*Functions for lexer*/

void	create_lexer(t_lexer *lexer, size_t cap);
t_lexer	*malloc_lexer(size_t cap);
void	handle_token(t_lexer *lexer, t_token token);
void	add_token_to_lexer(t_lexer *lexer, const char *s, size_t len,
			t_ttype type);
void	double_lexer(t_lexer *lexer);
void	tokenize(t_lexer *lexer);
int		check_error(t_lexer *lexer);
void	reassemble_quotes(t_lexer *lexer);
void	substitutions(t_lexer *lexer, t_env *env);
void	delete_quotes(t_lexer *lexer);
t_token	handle_substitution(char *input, t_env *env, t_token *rlist);

/*Functions for tokens*/

t_token	create_token(const char *str, size_t len, t_ttype type);
t_token	*malloc_token(const char *s, size_t len, t_ttype type);
t_token	handle_quote(char *input, char c);
t_token	get_token(char *input, t_token *rlist);

/* Utils parsing */

int		is_space(char c);
char	*create_str(char *input, int i);
int		is_separator(char *input, t_token *rlist);
int		delimite_word(char *input, int i, t_token *rlist);
int		delimite_word_substi(char *input, int i, t_token *rlist);
char	*delete_quote(char *str, int i);
char	**join_token(char **args);
size_t	count_pipe(t_token **tokens, size_t lexer_size);
int		d_great(t_cmd *cmd, t_token **tokens, int pos, int lexer_size);
int		great(t_cmd *cmd, t_token **tokens, int pos, int lexer_size);
int		less(t_cmd *cmd, t_token **tokens, int pos, int lexer_size);

#endif
