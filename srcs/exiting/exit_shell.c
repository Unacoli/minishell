/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:23:23 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/09 15:02:15 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* destroy_shell == exit_free */

void	exit_shell(t_ctrl *minishell)
{
	exit_free(minishell);
	exit(0);
}
