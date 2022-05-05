/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:38:59 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/05 15:21:36 by ldubuche         ###   ########.fr       */
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

static int	is_space(char c)
{
	if (c == ' ' || c == '\v' || c == '\t' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

static t_regex	handle_word(char *inout, t_lexer *lexer)
{
	int		i;
	char	*str;

	i = 1;
	while (input[i] && !is_space(input[i]))
		i++;
	str = create_str(input, i);
	return ((t_regex){str, i, TOKEN_WORD});
}

char	*create_str(char *input, int i)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * (*i + 2));
	if (!str)
	{
		exit (0); //free lexer + tokens
	}
	ft_strlcpy(str, *input, (size_t)(*i + 1));
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
	if (*input == '$')
		return (handle_substitution(input, lexer));
	else
		return (handle_word(input, lexer));
	return (g_rlist[TOKEN_NOT_VALID]);
}
