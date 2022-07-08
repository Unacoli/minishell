/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:12:29 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/08 04:39:52 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Besoin du token word just apres + deplace la position de deux */
/* Doit etre suivi d'un token WORD */

int less(t_cmd *cmd, t_token **tokens, int pos, int lexer_size)
{
	if (pos + 1 < lexer_size && tokens[pos + 1]->type == TOKEN_WORD)
	{
		cmd->input_file = open(tokens[pos + 1]->str, O_RDONLY);
		if (cmd->input_file >= 0)
			return (0);
		else
		{
			perror("Open");
			return (1);
		}
	}
	else
	{
		printf("Syntax error near token LESS\n");
		return  (1);
	}
	return (1);
}
