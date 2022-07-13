/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/13 18:08:44 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input(t_ctrl *minishell)
{
	int		cmd;

	cmd = ft_command(minishell);
	if (cmd != -1)
	{
		if (treat_token(minishell))
			choose_execve(minishell->cmd->ac, minishell);
		else
		{
			g_status = 1;
			free_cmd(minishell->cmd);
		}
	}
	if (minishell->lexer)
		free_lexer(minishell->lexer);
}
