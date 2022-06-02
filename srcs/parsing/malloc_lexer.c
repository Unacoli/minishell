/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:37:20 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/02 10:13:01 by ldubuche         ###   ########.fr       */
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
