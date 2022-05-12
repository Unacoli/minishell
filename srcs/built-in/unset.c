/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:39:27 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/12 14:40:13 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char *cmd, t_env *un)
{
	t_env	*prev;

	un = un->deb;
	prev = NULL;
	while (un)
	{
		if (ft_strncmp(un->name, cmd, ft_strlen(un->name) + 1) == 0)
		{
			if (prev)
			{
				prev->next = un->next;
			}
			else
				changedeb(un->next);
			free(un->name);
			free(un->value);
			free(un);
			break ;
		}
		prev = un;
		un = un->next;
	}
}

void	changedeb(t_env *un)
{
	t_env	*deb;

	deb = un;
	while (un)
	{
		un->deb = deb;
		un = un->next;
	}
}
