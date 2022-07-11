/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:25:32 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/11 03:05:22 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrlc_normal(int num)
{
	(void)num;
	printf("\n");
	rl_replace_line("", 1);
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
	if (signal(SIGINT, ctrlc_normal) == SIG_ERR)
		sig_err();
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		sig_err();
}
