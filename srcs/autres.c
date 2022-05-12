/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autres.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:57:27 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/05/12 14:55:03 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child(char *path, char **argv, char**env, char *name)
{
	if (execve(path, argv, env) == -1)
		printf("%s: command not found\n", name + 1);
	freetab(env);
	free(name);
	freetab(argv);
	free(path);
}

void	addele(t_env *un, char **retsplit)
{
	int	j;

	un->name = retsplit[0];
	un->haveeq = 1;
	un->value = retsplit[1];
	if (retsplit[2])
	{
		j = 2;
		while (retsplit[j])
		{
			un->value = ft_strjoinchar(un->value, '=');
			un->value = ft_strjoin_free2(un->value, retsplit[j]);
			j++;
		}
	}
}
