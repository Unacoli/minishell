/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:44:29 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/04/11 17:09:29 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exitfree(t_env *un)
{
	t_env	*deux;

	un = un->deb;
	while (un)
	{
		deux = un->next;
		free(un->name);
		free(un->value);
		free(un);
		un = deux;
	}
	exit(0);
}

void	freeenv(t_env *un)
{
	t_env	*deux;

	un = un->deb;
	while (un)
	{
		deux = un->next;
		free(un->name);
		free(un->value);
		free(un);
		un = deux;
	}
}
