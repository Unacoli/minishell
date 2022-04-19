/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:38:59 by nargouse          #+#    #+#             */
/*   Updated: 2022/04/19 22:07:40 by nargouse         ###   ########.fr       */
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

int	back_char(t_lexer *lexer, char **token_s)
{
	if (lexer->input[lexer->pos + 1])
	{
		push_char(lexer, token_s);
		push_char(lexer, token_s);
		return (0);
	}
	return (1);
}

int	push_char(t_lexer *lexer, char **token_s)
{
	ft_strlcat(*token_s, lexer->input + lexer->pos, 1);
	if (!(*token_s))
		return (-1);
	lexer->pos++;
	return (0);
}

void	get_next_token(t_lexer *lexer)
{
	lexer->pos += 1;
}

t_regex	get_token(char *input)
{
	int	i;

	i = 0;
	while (i < MAX_TOKENS)
	{
		if (!ft_strncmp(g_rlist[i].op, input, g_rlist[i].len))
			return (g_rlist[i]);
		i++;
	}
	return (g_rlist[TOKEN_NOT_VALID]);
}
