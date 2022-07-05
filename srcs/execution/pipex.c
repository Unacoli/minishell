/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:28:29 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/05 15:15:54 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Une fonction qui recoit une structure ou deux ? (simplecmd) et qui doit pipe
	l'output de la premiere commande dans la deuxieme */

// Besoin de l'environnement
// Besoin d'un fichier d'input et d'un output
// Besoin des deux commandes et de leurs arguments respectif si c'est sous form de char * c'est le meilleur
/* typedef struct cmd
{
	int	input;
	int output;
	char	**cmds;
} t_cmd;*/
int	pipex(t_cmd *cmd, t_env *env)
{
	t_pipe	pipe;
	int		i;

	i = 0;
	pipe.fd1 = cmd->input;
	pipe->fd2 = cmd->output;
	pipe->cmd = cmd->cmds;
	pipe.env_path = search_env(*env, "PATH");
	if (pipe.env_path != NULL)
	{
		pipe.cmd_paths = split(pipe.env_path, ':');
		if (pipe.cmd_paths == NULL)
			return (error("Split fail", &pipex));
	}
	pipe_time(&pipex);
	while (i < 2)
		child_bonus(pipex, i);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	free_close(&pipex);
	return (0);

}

char	*path(t_data_b *pipex)
{
	int	i;

	i = 0;
	while (pipex->envp[i] != NULL)
	{
		if (strnstr(pipex->envp[i], "PATH", 4) != NULL)
			return (pipex->envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	pipe_time(t_data_b *pipex)
{
	if (pipe(pipex->pipe) < 0)
		error("Pipe process fail", pipex);
}
static char	*cmd(char **paths, char *cmd, t_data_b *pipex)
{
	char	*tmp;
	char	*command;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = strjoin(paths[i], "/");
		if (tmp == NULL)
			error("Strjoin fail", pipex);
		command = strjoin(tmp, cmd);
		if (tmp == NULL)
		{
			free(tmp);
			error("Strjoin fail", pipex);
		}
		free(tmp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	close_pipes(t_data_b *pipex)
{
	int	i;

	i = 0;
	while (i < 2))
	{
		if (pipex->pipe[i] != -1)
		{
			close(pipex->pipe[i]);
			pipex->pipe[i] = -1;
		}
		i++;
	}
}

static void	redirection(int fd_0, int fd_1)
{
	dup2(fd_0, 0);
	dup2(fd_1, 1);
}

void	child_bonus(t_pipe pipex, int i)
{
	pipex.id = fork();
	if (pipex.id == 0)
	{
		if (i == 0)
			redirection(pipex.fd1, pipex.pipe[1]);
		else if (i == 1)
			redirection(pipex.pipe[0], pipex.fd2);
		close_pipes(&pipex);
		pipex.cmd_arg = split(pipex.cmd[i], ' ');
		if (pipex.cmd_arg == NULL)
			error("Split fail", &pipex);
		if (access(pipex.cmd_arg[0], X_OK) == 0)
			execve(pipex.cmd_arg[0], pipex.cmd_arg, pipex.envp);
		pipex.cmd = cmd(pipex.cmd_paths, pipex.cmd_arg[0], &pipex);
		if (!pipex.cmd)
		{
			error("command not found", &pipex);
			exit(1);
		}
		execve(pipex.cmd, pipex.cmd_arg, pipex.envp);
	}
}