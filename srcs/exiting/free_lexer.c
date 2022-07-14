/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:55:08 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/03 11:40:58 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_lexer *lexer)
{
	size_t	i;

	i = 0;
	if (lexer->tokens)
	{
		while (i < lexer->size)
		{
			if (lexer->tokens[i])
			{
				if (lexer->tokens[i]->str)
					free(lexer->tokens[i]->str);
				free(lexer->tokens[i]);
			}
			i++;
		}
		free(lexer->tokens);
		lexer->size = 0;
		lexer->capacity = 0;
	}	
}

void	free_lexer(t_lexer *lexer)
{
	if (lexer)
	{
		free_tokens(lexer);
		free(lexer);
	}
}
