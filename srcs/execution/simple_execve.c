/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:35:55 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/12 14:57:29 by ldubuche         ###   ########.fr       */
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

static int	env_len(t_env *env)
{
	int		len;
	t_env	*temp;

	len = 0;
	temp = env;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

char	*p_cmd(char **envp, char *cmd)
{
	char	*tmp;
	char	*command;
	char	**paths;
	int		i;

	i = 0;
	paths = ft_split(path(envp), ':');
	while (paths && paths[i])
	{
		tmp = ft_strjoin_free1(paths[i++], "/");
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
	}
	free_split(paths, i);
	return (NULL);
}

char	**transform_env(t_env env)
{
	char	**envp;
	int		len;
	t_env	*temp;
	int		i;

	len = env_len(&env);
	envp = (char **) malloc(sizeof(char *) * (len + 1));
	temp = &env;
	i = 0;
	while (temp)
	{
		envp[i] = temp->line;
		i++;
		temp = temp->next;
	}
	envp[i] = NULL;
	return (envp);
}

int	simple_execve(t_cmd *cmd, t_env env, t_ctrl *minishell)
{
	int		id;
	int		wstatus;
	char	*cmd_path;
	char	**envp;

	id = fork();
	if (id == 0)
	{
		envp = transform_env(env);
		redirection(cmd->input_file, cmd->output_file);
		close_fd(cmd);
		if (access(cmd->av[0][0], X_OK) == 0)
			execve(cmd->av[0][0], cmd->av[0], envp);
		cmd_path = p_cmd(envp, cmd->av[0][0]);
		if (!cmd_path)
			error_exit(cmd->av[0][0], minishell);
		execve((const char *)cmd_path, cmd->av[0], envp);
		perror("Execve");
		exit(errno);
	}
	waitpid(id, &wstatus, 0);
	g_status = status_handler(wstatus);
	return (1);
}
