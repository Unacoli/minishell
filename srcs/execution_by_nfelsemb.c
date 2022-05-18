/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_by_nfelsemb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:10:34 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/18 12:13:38 by ldubuche         ###   ########.fr       */
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

void	child(char *path, char **argv, char**env, char *name)
{
	if (execve(path, argv, env) == -1)
		printf("%s: command not found\n", name + 1);
	freetab(env);
	free(name);
	freetab(argv);
	free(path);
}

void	chldexed(char *cmd, t_env *envi)
{
	char	**argv;
	char	**env;
	char	*path;

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
	freetab(argv);
	freetab(env);
	exit(6);
}

void	exed(char *cmd, t_env *envi)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		chldexed(cmd, envi);
	else
		waitpid(pid, 0, 0);
}
