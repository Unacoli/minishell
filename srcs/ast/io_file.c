/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 04:06:24 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/02 02:35:26 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_io_file(t_ast *ast, t_lexer *lexer)
{
	t_token	*token;

	token = lexer->tokens[lexer->pos];
	if ((token->type == TOKEN_LESS || token->type == TOKEN_GREAT
		|| token->type == TOKEN_DGREAT || token->type == TOKEN_DLESS)
		&& lexer->size >= 2)
	{
		if (lexer->tokens[lexer->pos + 1]->type == TOKEN_WORD)
		{
			ast->right = malloc_ast(NODE_WORD, token->str);
			lexer->pos += 2;
			return (1);
		}
	}
	lexer->pos++;
	return (0);
}

int	io_file(t_ast *ast, t_lexer *lexer)
{
	if (parse_io_file(ast, lexer))
	{
		return (1);
	}
	return (0);
}
