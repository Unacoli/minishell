/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:22:10 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/04/06 14:34:40 by nfelsemb         ###   ########.fr       */
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
	while (*cmd != ' ')
	{
		name = ft_strjoinchar(name, *cmd);
		cmd++;
	}
	while (pa[i])
	{
		path = ft_strjoin(pa[i], name);
		if (access(path, X_OK))
		{
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}

void	lexe(char *cmd, t_env *envi)
{
	int		pid;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		path = getpath(cmd, envi);
		while (*cmd != ' ')
			cmd++;
		if (path)
			execve(path, ft_split(cmd, ' '), getenvchar(envi));
		else
			perror("minishell: command not found");
	}
	else
		waitpid(pid, 0, 0);
}
