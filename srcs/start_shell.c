/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:06:26 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/22 21:26:43 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_ctrl *minishell)
{
	minishell->lexer = NULL;
	minishell->ast = NULL;
	minishell->cmd = NULL;
	minishell->env = NULL;
}

int	running_shell(t_ctrl *minishell)
{
	while (1)
		ft_input(minishell);
	/*free all if minishell stop*/
	return (0);
}
