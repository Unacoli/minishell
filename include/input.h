/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:45:15 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/08 03:14:37 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

/*Functions for input processing*/

void	ft_input(t_ctrl *minishell);
int		ft_command(t_ctrl *minishell);
size_t	count_pipe(t_token **tokens, size_t lexer_size);

/*Signal handler*/

void	signal_handler(void);
void	error(int signal);

#endif
