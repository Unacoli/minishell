/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:25:32 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/09 16:55:51 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(int signal)
{
	(void) signal;
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

static void	sig_err(void)
{
	printf("signal failed");
	exit(1);
}

void	signal_handler(void)
{
	if (signal(SIGINT, error) == SIG_ERR)
		sig_err();
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		sig_err();
}
