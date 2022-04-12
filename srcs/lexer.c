/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:37:20 by nargouse          #+#    #+#             */
/*   Updated: 2022/04/12 15:49:47 by nargouse         ###   ########.fr       */
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

void	get_next_token(t_lexer *lexer)
{
	lexer->pos += 1;
}

int	pass(t_lexer *lexer, t_tok_type needed)
{
	if ((lexer->pos < lexer->size)
		&& (lexer->tokens[lexer->pos]->type == needed))
	{
		get_next_token(lexer);
		return (1);
	}
	return (0);
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
