/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:35:55 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/09 15:52:57 by ldubuche         ###   ########.fr       */
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
	char	*cmd_path;
	char	**envp;
	// char	*buff;
	// int i;

	if (ft_strncmp(cmd->av[0][0], "exit", ft_strlen(cmd->av[0][0])) == 0)
		exit_shell(minishell);
	id = fork();
	envp = transform_env(env);
	if (id == 0)
	{
		redirection(cmd->input_file, cmd->output_file);
		if (cmd->input_file != 0)
			close(cmd->input_file);
		if (cmd->output_file != 1)
			close(cmd->output_file);
		// buff = malloc(sizeof(char) *202);
		// i = read(0, buff, 200);
		// buff[i] = '\0';
		// printf("buff = %s", buff);
		// fprintf(stdout, "output 3\n");
		if (built_in(cmd->av[0], &env, minishell) == 0)
			return (1);
		else if (access(cmd->av[0][0], X_OK) == 0)
		{
			printf("Enter exeption\n");
			execve(cmd->av[0][0], cmd->av[0], envp);
		}
		// fprintf(stderr, "output 2,5\n");
		cmd_path = p_cmd(envp, cmd->av[0][0]);
		// fprintf(stdout, "output 2\n");
		if (!cmd_path)
		{
			fprintf(stderr, "command not found %s\n", cmd->av[0][0]);
			exit(1);
		}
		// fprintf(stdout, "output 1\n");
		execve((const char *)cmd_path, cmd->av[0], envp);
		perror("Execve");
	}
	waitpid(-1, NULL, 0);
	return (1);
}
