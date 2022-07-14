/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:03:37 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/12 10:57:41 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lexer_full(t_lexer *lexer)
{
	return (lexer->size == lexer->capacity);
}

void	add_token_to_lexer(t_lexer *lexer, const char *s, size_t l, t_ttype typ)
{
	if (lexer_full(lexer))
		double_lexer(lexer);
	lexer->tokens[lexer->size] = malloc_token(s, l, typ);
	lexer->size += 1;
}

void	handle_token(t_lexer *lexer, t_token token)
{
	add_token_to_lexer(lexer, token.str, ft_strlen(token.str), token.type);
	lexer->pos += token.len;
}
