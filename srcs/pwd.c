/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:27:51 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/04/01 13:50:49 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pwd(void)
{
	char	*buf;

	buf = ft_calloc(50, sizeof(char));
	getcwd(buf, 50);
	buf = ft_strjoinchar(buf, '\n');
	return (buf);
}

char	*envi(t_env *un)
{
	char	*d;

	d = ft_strdup("");
	un = un->deb;
	while (un)
	{
		if (un->haveeq)
		{
			d = ft_strjoin(d, un->name);
			d = ft_strjoinchar(d, '=');
			if (un->value)
				d = ft_strjoin(d, un->value);
			d = ft_strjoinchar(d, '\n');
		}
		un = un->next;
	}
	return (d);
}

char	*export(char *cmd, t_env *un)
{
	char	**retsplit;
	char	*d;

	un = un->deb;
	if (*cmd)
	{
		while (un->next)
			un = un->next;
		un->next = ft_calloc(1, sizeof(t_env));
		un = un->next;
		retsplit = ft_split(cmd, '=');
		un->name = retsplit[0];
		un->value = retsplit[1];
		if (ft_strchr(cmd, '='))
			un->haveeq = 1;
		else
			un->haveeq = 0;
	}
	else
	{
		d = ft_strdup("");
		while (un)
		{
			d = ft_strjoin(d, "declare -x ");
			d = ft_strjoin(d, un->name);
			if (un->haveeq)
			{
				d = ft_strjoin(d, "=\"");
				if (un->value)
					d = ft_strjoin(d, un->value);
				d = ft_strjoinchar(d, '\"');
			}
			d = ft_strjoinchar(d, '\n');
			un = un->next;
		}
		return (d);
	}
	return (NULL);
}

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
			free(un);
			break ;
		}
		prev = un;
		un = un->next;
	}
}

char	*cd(char	*cmd)
{
	if (chdir(cmd))
		return (ft_strjoin(cmd, ": No such file or directory\n"));
	return (0);
}
