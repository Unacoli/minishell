/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:03:37 by nargouse          #+#    #+#             */
/*   Updated: 2022/04/14 16:34:19 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token_to_lexer(t_lexer *lexer, const char *s, size_t len, t_ttype type)
{
	if (lexer_full(lexer))
		/* add function to double the size of the lexer*/
	lexer->tokens[lexer->size] = malloc_token(s, len, type);
	lexer->size += 1;
}

void	add_word_to_lexer(t_lexer *lexer, char **token_s)
{
	add_token_to_lexer(lexer, *token_s, ft_strlen(*token_s), TOKEN_WORD);
	ft_strdel(*token_s, ft_strlen(*token_s));
}
