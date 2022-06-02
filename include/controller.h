/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:25:12 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 14:27:17 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

/*Struct for controller*/

typedef struct s_ctrl
{
	t_lexer	*lexer;
	t_ast	*ast;
	t_cmd	*cmd;
	t_env	*env;
}				t_ctrl;

#endif