/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_great.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:43 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/09 17:43:35 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int less_great(t_token *token, t_ctrl *minishell)
{
	if (token->type == TOKEN_LESS)
	{
		if (!less(minishell->cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
			return (0);
	}
	else if (token->type == TOKEN_GREAT)
	{
		if (!great(minishell->cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
			return (0);
	}
	else if (token->type == TOKEN_DGREAT)
	{
		if (!d_great(minishell->cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
			return (0);
	}
	else if (token->type == TOKEN_DLESS)
	{
		if (!d_less(minishell->cmd, minishell, minishell->lexer->pos, minishell->lexer->size))
			return (0);
	}
	return (1);
}