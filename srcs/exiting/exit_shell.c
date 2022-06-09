/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:23:23 by nargouse          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/03 11:56:13 by ldubuche         ###   ########.fr       */
=======
/*   Updated: 2022/06/09 04:15:16 by nargouse         ###   ########.fr       */
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
// void	destroy_shell(t_ctrl *minishell)
// {
// 	if (minishell->lexer)
// 		free_lexer(&(minishell->lexer));
// 	if (minishell->ast)
// 		/*Function to free ast*/
// 	if (minishell->cmd)
// 		/*Function to free cmd*/
// 	if (minishell->env)
// 		free_env(&(minishell->env));
// }
=======
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
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880

void	exit_shell(t_ctrl *minishell)
{
	exit_free(minishell);
	exit(0);
}
