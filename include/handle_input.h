/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:45:15 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 10:29:27 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_INPUT_H
# define HANDLE_INPUT_H

/*Functions for input processing*/

void	ft_input(t_ctrl *minishell);
int		ft_command(t_ctrl *minishell);

/*Signal handler*/

void	signal_handler(void);
void	error(int signal);

#endif