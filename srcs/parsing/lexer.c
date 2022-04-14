/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:37:20 by nargouse          #+#    #+#             */
/*   Updated: 2022/04/14 17:15:39 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_lexer(t_lexer *lexer, size_t cap)
{
	lexer->pos = 0;
	lexer->size = 0;
	lexer->capacity = cap;
	lexer->input = NULL;
	lexer->tokens = ft_calloc((cap + 1), sizeof(t_token *));
}

t_lexer	*malloc_lexer(size_t cap)
{
	t_lexer	*result;

	result = malloc(sizeof(t_lexer));
	if (!result)
		return (NULL);
	create_lexer(result, cap);
	return (result);
}

int	lexer_full(t_lexer *lexer)
{
	return (lexer->size == lexer->capacity);
}

int	pass(t_lexer *lexer, t_ttype needed)
{
	if ((lexer->pos < lexer->size)
		&& (lexer->tokens[lexer->pos]->type == needed))
	{
		get_next_token(lexer);
		return (1);
	}
	return (0);
}
