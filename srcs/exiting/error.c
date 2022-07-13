/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:57:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 20:01:41 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_message(char *msg, int ret)
{
	if (msg == NULL)
	{
		perror("minishell");
		g_status = errno;
		return (errno);
	}
	else
	{
		printf("minishell: %s\n", msg);
		g_status = ret;
		return (ret);
	}
}

void	error_exit(char *str, t_ctrl *minishell, char **envp)
{
	free(envp);
	ft_putstr_fd("Command not found ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	g_status = 127;
	exit_free(minishell);
}
