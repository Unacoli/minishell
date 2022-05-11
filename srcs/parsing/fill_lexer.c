/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:03:37 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/11 16:45:40 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token_to_lexer(t_lexer *lexer, const char *s, size_t l, t_ttype typ)
{
	if (lexer_full(lexer))
		double_lexer(lexer);
	lexer->tokens[lexer->size] = malloc_token(s, l, typ);
	lexer->size += 1;
}

void	handle_token(t_lexer *lexer, t_regex token)
{
	if (token.type != TOKEN_PASS)
		add_token_to_lexer(lexer, token.op, token.len, token.type);
	lexer->pos += token.len;
}
