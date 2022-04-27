/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:59:46 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/04/27 17:23:46 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*initenv(char **env)
{
	t_env	*un;
	t_env	*deux;
	char	**retsplit;
	int		i;
	int		j;

	un = ft_calloc(1, sizeof(t_env));
	un->deb = un;
	un->next = NULL;
	retsplit = ft_split(env[0], '=');
	un->name = retsplit[0];
	un->haveeq = 1;
	un->value = retsplit[1];
	free(retsplit);
	i = 1;
	while (env[i])
	{
		deux = un;
		un = ft_calloc(1, sizeof(t_env));
		un->deb = deux->deb;
		deux->next = un;
		un->next = NULL;
		retsplit = ft_split(env[i], '=');
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
		free(retsplit);
		i++;
	}
	return (un->deb);
}

char	*ft_strjoinchar(char const *s1, char const s2)
{
	int		i;
	int		len1;
	char	*dest;

	len1 = ft_strlen(s1);
	dest = malloc(sizeof(char) * (len1 + 2));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	dest[len1] = s2;
	len1++;
	dest[len1] = '\0';
	free((char *)s1);
	return (dest);
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

void	exed(char *cmd, t_env *envi)
{
	char	**argv;
	char	**env;
	char	*path;

	int (i), pid;
	pid = fork();
	if (pid == 0)
	{
		argv = ft_split(cmd, ' ');
		free(cmd - 1);
		cmd = argv[0];
		env = getenvchar(envi);
		path = ft_strdup(".");
		path = ft_strjoin_free1(path, cmd);
		freeenv(envi);
		argv[0] = path;
		if (execve(path, argv, env) == -1)
			printf("minishell: %s: No such file or directory\n", "p");
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
		i = 0;
		while (env[i])
		{
			free(env[i]);
			i++;
		}
		free(env);
		exit(6);
	}
	else
		waitpid(pid, 0, 0);
}
