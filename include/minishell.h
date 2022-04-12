/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:00:27 by nargouse          #+#    #+#             */
/*   Updated: 2022/04/12 16:46:52 by nargouse         ###   ########.fr       */
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

# define MAX_TOKENS 12

typedef enum e_tok_type
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
}				t_tok_type;

typedef struct s_regex
{
	const char	*op;
	size_t		len;
	t_tok_type	type;
}				t_regex;

typedef struct s_token
{
	char		*str;
	size_t		len;
	t_tok_type	type;
}				t_token;

typedef struct s_lexer
{
	size_t	pos;
	size_t	size;
	size_t	capacity;
	char	*input;
	t_token	**tokens;
}				t_lexer;

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
char	*cd(char	*cmd);
char	*echo(char	*cmd, t_env *enviro, int tiretn);
char	*getvale(char *name, t_env *un);
void	lexe(char *cmd, t_env *envi);
void	exitfree(t_env *un);
void	freeenv(t_env *un);
int		checkname(char *name);

struct s_env
{
	t_env	*deb;
	int		haveeq;
	char	*name;
	char	*value;
	t_env	*next;
};

#endif
