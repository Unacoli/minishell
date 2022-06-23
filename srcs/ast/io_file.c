/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 04:06:24 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/23 23:49:41 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_io_file(t_ast **ast, t_lexer *lexer)
{
	t_token	*token;

	token = lexer->tokens[lexer->pos++];
	if (token->type == TOKEN_GREAT)
		(*ast)->right = malloc_ast(NODE_WORD, lexer->tokens[lexer->pos]->str);
	return (1);
}

int	io_file(t_ast **ast, t_lexer *lexer)
{
	if (parse_io_file(ast, lexer))
	{
		return (1);
	}
	return (0);
}
