/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:35:00 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/08 04:52:18 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*simple_cmd(size_t pos, t_ctrl *minishell, t_cmd *cmd)
{
	int		i;

	i = 0;
	while (pos < minishell->lexer->size
			&& minishell->lexer->tokens[pos]->type == TOKEN_WORD)
	{
		cmd->av[i] = ft_strdup(minishell->lexer->tokens[pos]->str);
		pos++;
		i++;
	}
	cmd->ac = pos - i;
	minishell->lexer->pos += i;
	return (cmd);
}
