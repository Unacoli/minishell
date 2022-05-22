/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:25:32 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/13 01:34:24 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(int signal)
{
	if (signal == SIGINT)
	{
		close(STDIN_FILENO);
		dup(STDOUT_FILENO);
	}
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
