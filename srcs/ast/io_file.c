/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 04:06:24 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/09 13:56:14 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_io_file(t_ast **ast, t_lexer *lexer)
{
	t_token	*token;

	token = lexer->tokens[lexer->pos++];
	while (token->type == TOKEN_PASS)// pas de token pass
		token = lexer->tokens[lexer->pos++];
	if (token->type == TOKEN_NOT_VALID)// pas de token not valid
		return (0);
	else if (token->type == TOKEN_GREAT)
		(*ast)->right = malloc_ast(NODE_WORD, lexer->tokens[lexer->pos]->str); // Remplir les data
	return (1);
}

int	io_file(t_ast **ast, t_lexer *lexer)
{
	t_ast	*node;

	node = NULL;
	node = malloc_ast(node->type, node->data); // Inutile ? A toi de voir
	if (parse_io_file(ast, lexer))
	{
		*ast = node->right;
		return (1);
	}
	return (0);
}
