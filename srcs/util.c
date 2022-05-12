/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:59:46 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/05/12 14:54:23 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*initenv(char **env)
{
	t_env	*un;
	t_env	*deux;
	char	**retsplit;

	int (i) = 1;
	un = ft_calloc(1, sizeof(t_env));
	un->deb = un;
	un->next = NULL;
	retsplit = ft_split(env[0], '=');
	addele(un, retsplit);
	free(retsplit);
	while (env[i])
	{
		deux = un;
		un = ft_calloc(1, sizeof(t_env));
		un->deb = deux->deb;
		deux->next = un;
		un->next = NULL;
		retsplit = ft_split(env[i], '=');
		addele(un, retsplit);
		free(retsplit);
		i++;
	}
	return (un->deb);
}
