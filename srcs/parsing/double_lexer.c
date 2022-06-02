/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:18:58 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/02 10:12:47 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	**lexer_dup(t_token **token, int max, size_t n)
{
	t_token	**result;
	int		i;

	result = ft_calloc((n + 1), sizeof(t_token *));
	if (!result)
		return (NULL);
	i = 0;
	if (token && max)
	{
		while (token[i] && i < max)
		{
			result[i] = malloc_token(token[i]->str, token[i]->len, \
			token[i]->type);
			i++;
		}
	}
	return (result);
}

void	double_lexer(t_lexer *lexer)
{
	lexer->capacity *= 2;
	lexer->tokens = lexer_dup(lexer->tokens, lexer->size, lexer->capacity);
}
