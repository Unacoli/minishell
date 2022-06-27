/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:11:08 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/27 10:45:01 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse(t_ast **root, t_lexer *lexer)
{
	int	parsed;

	parsed = 1;
	lexer->pos = 0;
	create_root(root);
	while ((lexer->pos < lexer->size) && parsed != 0)
		parsed = parsed_command(root, lexer);
	if (lexer->pos < lexer->size)
		return (printf("Syntax Error"));
	return (0);
}
