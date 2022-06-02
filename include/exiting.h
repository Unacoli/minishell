/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:43:32 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 11:44:49 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXITING_H
# define EXITING_H

void	free_lexer(t_lexer *lexer);
void	free_env(t_env *env);
void	free_ast(t_ast **to_free);

int		error_message(char *msg, int ret);

/*Exit functions*/

void	exit_shell(t_ctrl *minishell);
void	destroy_shell(t_ctrl *minishell);
void	free_lexer(t_lexer *lexer);

#endif
