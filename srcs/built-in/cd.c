/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:40:42 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/12 15:40:11 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	J'ai du mal a voir ce qu'est cense contenir son input cmd
	mais je pense que l'on peut remplacer ce split immonde
	par une recherche d'espace */
char	*cd(char	*cmd, t_env	*envi)
{
	char	**retsplit;
	int		i;

	if (!*cmd)
	{
		cmd = getvale("HOME", envi);
	}
	else
		cmd++;
	i = 0;
	retsplit = ft_split(cmd, ' ');
	if (retsplit[1])
	{
		freetab(retsplit);
		return (ft_strdup("minishell: cd: too many arguments\n"));
	}
	while (retsplit[i])
	{
		free(retsplit[i]);
		i++;
	}
	free(retsplit);
	if (chdir(cmd))
		return (ft_strjoin(cmd, ": No such file or directory\n"));
	return (0);
}

char	*getvale(char *name, t_env *un)
{
	un = un->deb;
	while (un)
	{
		if (ft_strncmp(un->name, name, ft_strlen(name) + 1) == 0)
			return (un->value);
		un = un->next;
	}
	return (0);
}
