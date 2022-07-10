/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:25:32 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/10 18:05:07 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrlc_normal(int num)
{
	(void)num;
	ft_putchar_fd('\n', 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	ctrl_exec(int num)
{
	if (num == SIGINT)
		ft_putchar_fd('\n', 1);
	if (num == SIGQUIT)
		ft_putendl_fd("Quit (core dumped)", 2);
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

void	signal_handler_exec(void)
{
	if (signal(SIGINT, ctrl_exec) == SIG_ERR)
		sig_err();
	if (signal(SIGQUIT, ctrl_exec) == SIG_ERR)
		sig_err();
}
