/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:57:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/10 18:27:14 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_message(char *msg, int ret)
{
	if (msg == NULL)
	{
		perror("minishell");
		return (errno);
	}
	else
	{
		printf("minishell: %s\n", msg);
		return (ret);
	}
}

void	error_exit(char *str)
{
	ft_putstr_fd("Command not found ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	exit(1);
}
