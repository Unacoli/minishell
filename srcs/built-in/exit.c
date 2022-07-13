/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:44:34 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 16:27:50 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Appelle toute les fonctions free puis exit 
	*/

void	exit_free(t_ctrl *minishell)
{
	if (minishell)
	{
		if (minishell->lexer)
			free_lexer(minishell->lexer);
		if (minishell->env)
			free_env(minishell->env);
		if (minishell->cmd)
			free_cmd(minishell->cmd);
	}
	rl_clear_history();
	exit(g_status);
}
