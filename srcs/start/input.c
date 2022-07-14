/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/14 01:24:42 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input(t_ctrl *minishell)
{
	int		cmd;
	int		i;

	cmd = ft_command(minishell);
	i = 0;
	while (i < (int)minishell->lexer->size)
	{
		printf("%s\n", minishell->lexer->tokens[i]->str);
		i++;
	}
	// exit(0);
	// if (cmd != -1)
	// {
	// 	if (treat_token(minishell))
	// 	{	
	// 		choose_execve(minishell->cmd->ac, minishell);
	// 	}	
	// 	else
	// 	{
	// 		g_status = 1;
	// 		free_cmd(minishell->cmd);
	// 	}
	// }
	// if (minishell->lexer)
	// 	free_lexer(minishell->lexer);
}
