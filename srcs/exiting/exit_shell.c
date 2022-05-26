/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:23:23 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/26 14:41:34 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_shell(t_ctrl *minishell)
{
	if (minishell->lexer)
		free_lexer(&(minishell->lexer);
	if (minishell->ast)
		/*Function to free ast*/
	if (minishell->cmd)
		/*Function to free cmd*/
	if (minishell->env)
		free_env(&(minishell->env));
}

void	exit_shell(t_ctrl *minishell)
{
	destroy_shell(minishell);
	exit(0);
}
