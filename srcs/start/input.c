/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/10 17:25:37 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input(t_ctrl *minishell)
{
	int		cmd;
	size_t	i;

	cmd = ft_command(minishell);
	if (cmd != -1)
	{
		i = 0;
		while (i < minishell->lexer->size)
		{
			minishell->lexer->tokens[i]->str = \
			search_substi(minishell->env, minishell->lexer->tokens[i]->str);
			i++;
		}
		if (treat_token(minishell))
			choose_execve(minishell->cmd->ac, minishell);
	}
}
