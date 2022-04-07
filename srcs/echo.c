/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:22:10 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/04/07 16:13:21 by nfelsemb         ###   ########.fr       */
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

char	*echo(char	*cmd, t_env *enviro, int tiretn)
{
	char	*d;
	int		i;

	i = 0;
	d = ft_strdup("");
	while (cmd[i])
	{
		if (cmd[i] != '$')
			d = ft_strjoinchar(d, cmd[i]);
		else
		{
			i++;
			d = ft_strjoin(d, getvale(getname(cmd, i), enviro));
			while (cmd[i] != ' ' && cmd[i])
				i++;
		}
		i++;
	}
	if (tiretn)
		return (d);
	return (ft_strjoinchar(d, '\n'));
}

char	*getpath(char *cmd, t_env *enviro)
{
	char	*path;
	char	**pa;
	char	*name;
	int		i;

	i = 0;
	path = getvale("PATH", enviro);
	pa = ft_split(path, ':');
	name = ft_strdup("");
	while (*cmd != ' ' && *cmd)
	{
		name = ft_strjoinchar(name, *cmd);
		cmd++;
	}
	name = ft_strjoin("/", name);
	while (pa[i])
	{
		path = ft_strjoin(pa[i], name);
		if (access(path, X_OK) == 0)
		{
			return (path);
		}
		free(path);
		i++;
	}
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
		ret[i] = ft_strjoin(ret[i], enviro->value);
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

	pid = fork();
	if (pid == 0)
	{
		path = getpath(cmd, envi);
		argv = ft_split(cmd, ' ');
		argv[0] = path;
		printf("%s\n", argv[1]);
		if (execve(path, argv, getenvchar(envi)) == -1)	
			printf("minishell: command not found\n");
	}
	else
		waitpid(pid, &status, 0);
}
