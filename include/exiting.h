/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:43:32 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 20:02:00 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXITING_H
# define EXITING_H

/*Free functions*/

void	free_lexer(t_lexer *lexer);
void	free_tokens(t_lexer *lexer);
void	free_env(t_env *env);
void	free_cmd(t_cmd *cmd);
void	free_split(char **tab, int i);

/*Error functions*/

int		error_message(char *msg, int ret);

#endif