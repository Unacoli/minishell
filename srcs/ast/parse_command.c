/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:34:42 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/22 22:43:20 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
This function parses a command

return 1 if the node creation succeeded
0 otherwise
*/

static int	pipe_seq(t_ast **node, t_lexer *lexer)
{
	t_ast *node;

	node = /*Function to malloc an AST node*/
	if (/*Function to parse pipe seq*/)
	{
		/*Function to take right node*/
		return (1);
	}
	/*Function to free AST*/
	return (0);
}

int	parsed_command(t_ast **ast, t_lexer *lexer)
{
	int	parsed;

	parsed = pipe_seq(ast, lexer);
	if (parsed == 1)
	{
		while ((lexer->pos < lexer->size) && parsed == 1)
			parsed = pipe_seq(ast, lexer);
		return (1);
	}
	return (0);
}
