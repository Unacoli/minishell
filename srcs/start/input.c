/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/12 15:23:13 by nargouse         ###   ########.fr       */
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
	}
	if (minishell->lexer)
		free_lexer(minishell->lexer);
}
