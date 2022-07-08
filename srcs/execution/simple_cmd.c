/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:35:00 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/08 15:24:50 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_suffix(size_t pos, t_ctrl *minishell)
{
	char	**arg;
	int		i;

	i = pos;
	while (pos < minishell->lexer->size
			&& minishell->lexer->tokens[pos]->type == TOKEN_WORD)
		pos++;
	arg = (char **) malloc(sizeof(char *) * ((pos - i) + 1)); //verif malloc a faire
	pos = i;
	i = 0;
	while (pos < minishell->lexer->size
			&& minishell->lexer->tokens[pos]->type == TOKEN_WORD)
	{
		arg[i] = ft_strdup(minishell->lexer->tokens[pos]->str);
		pos++;
		i++;
	}
	arg[i] = NULL;
	minishell->lexer->pos += i - 1;
	return (arg);
}

// t_cmd	*simple_cmd(size_t pos, t_ctrl *minishell, t_cmd *cmd)
// {
// 	int		i;

// 	i = 0;
// 	while (pos < minishell->lexer->size
// 			&& minishell->lexer->tokens[pos]->type == TOKEN_WORD)
// 	{
// 		cmd->av[i] = ft_strdup(minishell->lexer->tokens[pos]->str);
// 		pos++;
// 		i++;
// 	}
// 	cmd->ac = pos - i;
// 	minishell->lexer->pos += i;
// 	return (cmd);
// }
