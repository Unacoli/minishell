/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:29:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/12 14:53:28 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*export(char *cmd, t_env *un)
{
	un = un->deb;
	if (*cmd)
		return (exportd(cmd, un));
	else
		return (exportun(un));
	return (NULL);
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

int	checkname(char *name)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(name[i]) || name[i] == '_'))
		return (0);
	i++;
	while (name[i])
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}
