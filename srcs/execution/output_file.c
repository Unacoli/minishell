/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:18:01 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/08 04:40:29 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	great(t_cmd *cmd, t_token **tokens, int pos, int lexer_size)
{
	if (pos + 1 < lexer_size && tokens[pos + 1]->type == TOKEN_WORD)
	{
		cmd->output_file = open(tokens[pos + 1]->str, O_CREAT | O_RDWR | O_TRUNC, 0000644);
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
		printf("Syntax error near token GREAT\n");
		return  (1);
	}
	return (1);
}

int	d_great(t_cmd *cmd, t_token **tokens, int pos, int lexer_size)
{
	if (pos + 1 < lexer_size && tokens[pos + 1]->type == TOKEN_WORD)
	{
		cmd->output_file = open(tokens[pos + 1]->str, O_WRONLY | O_CREAT | O_APPEND, 0000644);
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
		printf("Syntax error near token DGREAT\n");
		return  (1);
	}
	return (1);
}
