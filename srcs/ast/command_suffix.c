/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_suffix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:51:46 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/26 21:23:50 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_cmd_suffix(t_ast *ast, t_lexer *lexer)
{
	t_token *token;

	token = lexer->tokens[lexer->pos];
	if (token->type == TOKEN_WORD)
	{
		ast->right = malloc_ast(NODE_WORD, token->str);
		return (1);
	}
	else if (token->type == TOKEN_LESS || token->type == TOKEN_GREAT
		|| token->type == TOKEN_DGREAT || token->type == TOKEN_DLESS)
	{
		ast->left = malloc_ast(NODE_IO_FILE, token->str);
		ast->right = malloc_ast(NODE_WORD, token->str);
		return (1);
	}
	return (0);
}

int	cmd_suffix(t_ast *ast, t_lexer *lexer)
{
	if (parse_cmd_suffix(ast, lexer))
	{
		io_file(ast, lexer);
		return (1);		
	}
	return (0);
}
