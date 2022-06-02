/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:57:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 14:56:17 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_message(char *msg, int ret)
{
	if (msg == NULL)
	{
		perror(strerror(errno));
		return (errno);
	}
	else
	{
		printf("minishell: %s\n", msg);
		return (ret);
	}
}
