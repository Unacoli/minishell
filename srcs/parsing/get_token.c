/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:38:59 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/04 16:16:10 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_regex	g_rlist[] = {
{">>", 2, TOKEN_DGREAT},
{"<<", 2, TOKEN_DLESS},
{"\n", 1, TOKEN_NEWLINE},
{"|", 1, TOKEN_PIPE},
{">", 1, TOKEN_GREAT},
{"<", 1, TOKEN_LESS},
{" ", 1, TOKEN_PASS},
{"\v", 1, TOKEN_PASS},
{"\t", 1, TOKEN_PASS},
{"\r", 1, TOKEN_PASS},
{"\f", 1, TOKEN_PASS},
{NULL, 0, TOKEN_NOT_VALID}
};

/* 	Ajoute toute la partie entre guillemet jusu'au $ exclus dans un token
	Puis parcours l'input jusqu'a la fin de la variable d'enviro et ajoute un token
	Decale input et i pour correspondre a la nouvelle place */

static void	handle_dollard(int *i, char **input, t_lexer *lexer)
{
	char	*str;
	char	*inp;

	inp = *input;
	str = (char *) malloc(sizeof(char) * (*i + 2));
	ft_strlcpy(str, inp, (size_t)(*i + 1));
	add_token_to_lexer(lexer, str, *i, TOKEN_WORD_QUOTED);
	*input = *input + *i;
	inp = *input;
	*i = 1;
	while (inp[*i] && ((inp[*i] >= 'A' && inp[*i] <= 'Z') || inp[*i] == '_'))
		(*i)++;
	str = (char *) malloc(sizeof(char) * (*i + 3));
	ft_strlcpy(str, inp, (size_t)(*i + 2));
	add_token_to_lexer(lexer, str, *i, TOKEN_SUBSTITUTION);
	*input = *input + *i;
	*i = 0;
}

/*	Sauf combinaison $+"", parcoure tout l'input jusqu'a la quote correspondante
	Et le stocke dans un seul token */

static t_regex	handle_quote(char *input, t_lexer *lexer, char c)
{
	int		i;
	char	*str;

	i = 1;
	while (input[i] != c)
	{
		if (input[i] == '$' && c == DOUBLE_QUOTE)
			handle_dollard(&i, &input, lexer);
		i++;
		if (!input[i] && input[i] != c)
		{
			printf("Quote is not closed !");
			exit (0); //free lexer + tokens
		}
	}
	str = (char *) malloc(sizeof(char) * (i + 3));
	ft_strlcpy(str, input, i + 2);
	return ((t_regex){str, i + 1, TOKEN_WORD});
}

t_regex	get_token(char *input, t_lexer *lexer)
{
	int	i;

	i = 0;
	while (i < (MAX_TOKENS - 1))
	{
		if (!ft_strncmp(g_rlist[i].op, input, g_rlist[i].len))
			return (g_rlist[i]);
		i++;
	}
	i = 0;
	if (*input == DOUBLE_QUOTE || *input == SINGLE_QUOTE)
		return (handle_quote(input, lexer, *input));
	return (g_rlist[TOKEN_NOT_VALID]);
}
