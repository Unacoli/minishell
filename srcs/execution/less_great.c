/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_great.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:31:43 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/10 04:35:55 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	less_great(t_token *token, t_ctrl *ms)
{
	if (token->type == TOKEN_LESS)
	{
		if (!less(ms->cmd, ms->lexer->tokens, ms->lexer->pos, ms->lexer->size))
			return (0);
	}
	else if (token->type == TOKEN_GREAT)
	{
		if (!great(ms->cmd, ms->lexer->tokens, ms->lexer->pos, ms->lexer->size))
			return (0);
	}
	else if (token->type == TOKEN_DGREAT)
	{
		if (!d_great(ms->cmd, ms->lexer->tokens,
				ms->lexer->pos, ms->lexer->size))
		{
			return (0);
		}
	}
	else if (token->type == TOKEN_DLESS)
	{
		if (!d_less(ms->cmd, ms, ms->lexer->pos, ms->lexer->size))
			return (0);
	}
	return (1);
}
