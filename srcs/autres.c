/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autres.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:57:27 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/04/28 14:22:27 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child(char *path, char **argv, char**env)
{
	if (execve(path, argv, env) == -1)
		printf("minishell: command not found\n");
	freetab(env);
	freetab(argv);
	free(path);
	exit(6);
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

char	*exportun(t_env *un)
{
	char	*d;

	d = ft_strdup("");
	while (un)
	{
		d = ft_strjoin_free1(d, "declare -x ");
		d = ft_strjoin_free1(d, un->name);
		if (un->haveeq)
		{
			d = ft_strjoin_free1(d, "=\"");
			if (un->value)
				d = ft_strjoin_free1(d, un->value);
			d = ft_strjoinchar(d, '\"');
		}
		d = ft_strjoinchar(d, '\n');
		un = un->next;
	}
	return (d);
}

char	*rname(char **retsplit)
{
	char	*d;

	d = ft_strjoinchar(retsplit[0], '\n');
	free(retsplit[1]);
	free(retsplit);
	return (ft_strjoin_free("export: not an identifier: ", d));
}

char	*exportd(char *cmd, t_env *un)
{
	char	**retsplit;

	retsplit = ft_split(cmd, '=');
	if (checkname(retsplit[0]) == 0)
		return (rname(retsplit));
	while (un->next
		&& ft_strncmp(un->name, retsplit[0], ft_strlen(un->name) + 2) != 0)
		un = un->next;
	if (!un->next
		&& ft_strncmp(un->name, retsplit[0], ft_strlen(un->name) + 2) != 0)
	{
		un->next = ft_calloc(1, sizeof(t_env));
		un = un->next;
		un->name = retsplit[0];
	}
	else
		free(retsplit[0]);
	un->value = retsplit[1];
	free(retsplit);
	if (ft_strchr(cmd, '='))
		un->haveeq = 1;
	else
		un->haveeq = 0;
	return (NULL);
}
