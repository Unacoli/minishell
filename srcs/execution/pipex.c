/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:28:29 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 14:56:29 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Une fonction qui recoit une structure ou deux ? (simplecmd) et qui doit pipe
	l'output de la premiere commande dans la deuxieme */

void	free_pipex(t_pipe *pipex)
{
	if (pipex->pipe)
		free(pipex->pipe);
	if (pipex->id)
		free(pipex->id);
	free_split(pipex->cmd_paths, 0);
}

void	redir(t_pipe pipex, int i)
{
	if (i == 0)
		redirection(pipex.fd1, pipex.pipe[1]);
	else if (i == pipex.nbr_cmd - 1)
		redirection(pipex.pipe[2 * i - 2], pipex.fd2);
	else
		redirection(pipex.pipe[2 * i - 2], \
		pipex.pipe[2 * i + 1]);
	close_pipes(&pipex);
}

int	child_bonus(t_pipe pipex, int i, t_env *env, t_ctrl *minishell)
{
	char	**args;
	char	**envp;
	char	*cmd_path;

	pipex.id[i] = fork();
	if (pipex.id[i] == 0)
	{
		envp = transform_env(*env);
		redir(pipex, i);
		args = pipex.cmd[i];
		if (built_in(args, env, minishell, 1) == 0)
			exit (1);
		if (access(args[0], X_OK) == 0)
			execve(args[0], args, envp);
		cmd_path = p_cmd(envp, args[0]);
		if (!cmd_path)
		{
			fprintf(stderr, "%s : command not found\n", args[0]);
			g_status = 127;
			exit_shell(minishell);
		}
		execve((const char *)cmd_path, args, envp);
		perror("Pipex :");
	}
	return (1);
}

void	wait_childs(t_pipe *s_pipe)
{
	int	j;
	int	wstatus;

	j = 0;
	while (j < s_pipe->nbr_cmd)
	{
		waitpid(s_pipe->id[j], &wstatus, 0);
		if (j == s_pipe->nbr_cmd - 1)
			g_status = status_handler(wstatus);
		j++;
	}
}

int	pipex(t_cmd *cmd, t_env *env, t_ctrl *minishell)
{
	t_pipe	s_pipe;
	int		i;

	i = 0;
	init_pipex(&s_pipe, cmd, env);
	s_pipe.pipe = (int *) malloc(sizeof(int) * s_pipe.pipe_nbr);
	s_pipe.id = (int *) malloc(sizeof(int) * s_pipe.nbr_cmd);
	pipe_time(&s_pipe);
	while (i < s_pipe.nbr_cmd)
	{
		child_bonus(s_pipe, i, env, minishell);
		i++;
	}
	close_pipes(&s_pipe);
	wait_childs(&s_pipe);
	free_pipex(&s_pipe);
	return (0);
}
