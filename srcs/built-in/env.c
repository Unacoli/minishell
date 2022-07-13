/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:38:00 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 21:09:52 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	envi(t_env *env, int fd)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		ft_putstr_fd(temp->line, fd);
		ft_putstr_fd("\n", fd);
		temp = temp->next;
	}
	return (0);
}
