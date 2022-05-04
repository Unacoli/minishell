/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:34:25 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/04 13:36:35 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Back char, pour supprimer un backslash et get_next_token */
/*Je les ais mis la pour liberer de la place dans get_token */

int	back_char(t_lexer *lexer, char **token_s)
{
	if (lexer->input[lexer->pos + 1])
	{
		push_char(lexer, token_s);
		push_char(lexer, token_s);
		return (0);
	}
	return (1);
}

int	push_char(t_lexer *lexer, char **token_s)
{
	ft_strlcat(*token_s, lexer->input + lexer->pos, 1);
	if (!(*token_s))
		return (-1);
	lexer->pos++;
	return (0);
}

void	get_next_token(t_lexer *lexer)
{
	lexer->pos += 1;
}
