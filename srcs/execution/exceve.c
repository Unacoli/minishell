/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:35:55 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 10:09:32 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*__cmd(t_env env, char *cmd)
{
	char	*tmp;
	char	*command;
	char	**paths;
	int		i;

	i = 0;
	paths = ft_split(search_env(env, "PATH"), ":");
	while (paths[i])
	{
		tmp = __strjoin(paths[i], "/");
		if (tmp == NULL)
			printf("Strjoin fail\n");
		command = __strjoin(tmp, cmd);
		if (tmp == NULL)
		{
			free(tmp);
			printf("Strjoin fail\n");
		}
		free(tmp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

int	env_len(t_env env)
{
	int		len;
	t_env	*temp;

	temp = &env;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

char	**transform_env(t_env env)
{
	char	**envp;
	int		len;
	t_env	*temp;
	int		i;

	len = env_len(env);
	envp = (char *) malloc(sizeof(char) * len);
	temp = &env;
	i = 0;
	while (temp)
	{
		envp[i] = temp->line;
		i++;
		temp = temp->next;
	}
	return (envp);
}

int	call_exceve(char **cmd_arg, t_env env)
{
	int		id;
	char	**cmd_path;
	char	**envp;

	id = fork();
	envp = transform_env(env);
	if (id == 0)
	{
		if (access(cmd_arg[0], X_OK) == 0)
			execve(cmd_arg[0], cmd_arg, envp);
	}
	cmd_path = cmd(env, cmd_arg[0]);
	if (!cmd)
	{
		printf("command not found");
		exit(1);
	}
	execve(cmd, cmd_arg, envp);
}
