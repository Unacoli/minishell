/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:44:34 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/09 07:10:59 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Appelle toute les fonctions free puis exit 
	Il faudra rajouter les fonctions free_ast et free_cmd quand elle existeront
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
	exit(0);
}
