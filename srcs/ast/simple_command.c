/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:48:45 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/09 04:14:04 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_simple_command(t_ast **ast, t_lexer *lexer)
{
	t_token	*token;

	token = lexer->tokens[lexer->pos++];
	while (token->type == TOKEN_PASS) //pas de token pass
	{
		token = lexer->tokens[lexer->pos++];
	}
	if (token->type == TOKEN_NOT_VALID)// pas de token not valid
	{
		return (0);
	}
	else if (token->type == TOKEN_WORD)
	{
		(*ast)->left = malloc_ast(NODE_IO_FILE, \
		lexer->tokens[lexer->pos]->str); // Remplir les data
		(*ast)->right = malloc_ast(NODE_WORD, \
		lexer->tokens[lexer->pos]->str);
	}
	return (1);
}

int	simple_command(t_ast **ast, t_lexer *lexer)
{
	t_ast	*node;

	node = NULL;
	node = malloc_ast(node->type, node->data); // Inutile ? A toi de voir oui inutile + segfault
	if (parse_simple_command(ast, lexer))
	{
		io_file(ast, lexer); // Simplification de ouf pour tester
		*ast = node->right;
		return (1);
	}
	return (0);
}
