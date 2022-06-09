/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:23:23 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/09 04:15:16 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_shell(t_ctrl *minishell)
{
	if (minishell->lexer)
		free_lexer(minishell->lexer);
//	if (minishell->ast)
		/*Function to free ast*/
//	if (minishell->cmd)
		/*Function to free cmd*/
	if (minishell->env)
		free_env(minishell->env);
}

void	exit_shell(t_ctrl *minishell)
{
	destroy_shell(minishell);
	exit(0);
}
