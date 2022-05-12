/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:22:10 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/05/12 14:54:48 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getname(char *cmd, int i)
{
	char	*name;

	name = ft_strdup("");
	while (cmd[i] != ' ' && cmd[i])
	{
		name = ft_strjoinchar(name, cmd[i]);
		i++;
	}
	return (name);
}

char	*getpath(char *cmd, t_env *enviro)
{
	char	*path;
	char	**pa;
	char	*name;

	int (i) = 0;
	path = getvale("PATH", enviro);
	pa = ft_split(path, ':');
	name = getna(cmd);
	while (pa[i])
	{
		path = ft_strjoin(pa[i], name);
		if (access(path, X_OK) == 0)
		{
			freetr(pa, name, i);
			return (path);
		}
		free(path);
		free(pa[i]);
		i++;
	}
	free(pa);
	free(name);
	return (NULL);
}

char	**getenvchar(t_env *enviro)
{
	int		i;
	char	**ret;

	i = 0;
	while (enviro->next)
	{
		enviro = enviro->next;
		i++;
	}
	ret = ft_calloc(i + 1, sizeof(char *));
	enviro = enviro->deb;
	i = 0;
	while (enviro->next)
	{
		ret[i] = ft_strdup(enviro->name);
		ret[i] = ft_strjoinchar(ret[i], '=');
		ret[i] = ft_strjoin_free1(ret[i], enviro->value);
		i++;
		enviro = enviro->next;
	}
	ret[i] = NULL;
	return (ret);
}

void	lexe(char *cmd, t_env *envi)
{
	int		pid;
	int		status;
	char	*path;
	char	**argv;
	char	**env;

	signal(SIGINT, childctrlc);
	signal(SIGQUIT, coredump);
	pid = fork();
	if (pid == 0)
	{
		path = getpath(cmd, envi);
		argv = ft_split(cmd, ' ');
		free(argv[0]);
		if (path)
			argv[0] = path;
		env = getenvchar(envi);
		freeenv(envi);
		child(path, argv, env, getna(cmd));
		free(cmd);
		exit(6);
	}
	else
		waitpid(pid, &status, 0);
}
