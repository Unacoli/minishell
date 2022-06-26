/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:48:45 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/26 19:45:33 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_simple_command(t_ast *ast, t_lexer *lexer)
{
	t_token	*token;

	token = lexer->tokens[lexer->pos];
	if (token->type == TOKEN_WORD)
	{
		ast->right = malloc_ast(NODE_WORD, token->str);
		return (1);
	}
	return (0);
}

int	simple_command(t_ast *ast, t_lexer *lexer)
{
	printf("before parse simple cmd\n");
	if (parse_simple_command(ast, lexer))
	{
		cmd_suffix(ast, lexer);
		return (1);
	}
	return (0);
}
