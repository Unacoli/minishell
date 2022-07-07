/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:35:55 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/07 18:08:42 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH", 4) != NULL)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*cmd(char **envp, char *cmd)
{
	char	*tmp;
	char	*command;
	char	**paths;
	int		i;

	i = 0;
	paths = ft_split(path(envp), ':');
	while (paths[i])
	{
		tmp = ft_strjoin_free1(paths[i], "/");
		if (tmp == NULL)
			printf("Strjoin fail\n");
		command = ft_strjoin(tmp, cmd);
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

	len = 0;
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
	envp = (char **) malloc(sizeof(char *) * len);
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

int	simple_execve(t_cmd *s_cmd, t_env env, t_ctrl *minishell)
{
	int		id;
	char	*cmd_path;
	char	**envp;

	id = fork();
	envp = transform_env(env);
	if (id == 0)
	{
		redirection(s_cmd->input, s_cmd->output);
		if (built_in(s_cmd->cmds[0], &env, minishell) == 0)
			return (1);
		if (access(s_cmd->cmds[0][0], X_OK) == 0)
			execve(s_cmd->cmds[0][0], s_cmd->cmds[0], envp);
		cmd_path = cmd(envp, s_cmd->cmds[0][0]);
		if (!cmd_path)
		{
			fprintf(stderr, "command not found %s\n", cmd_path);
			exit(1);
		}
		execve((const char *)cmd_path, s_cmd->cmds[0], envp);
	}
	waitpid(-1, NULL, 0);
	return (1);
}
