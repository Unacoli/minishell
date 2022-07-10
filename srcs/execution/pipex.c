/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:28:29 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/10 18:26:15 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Une fonction qui recoit une structure ou deux ? (simplecmd) et qui doit pipe
	l'output de la premiere commande dans la deuxieme */

void	redirection(int fd_0, int fd_1)
{
	dup2(fd_0, 0);
	dup2(fd_1, 1);
}

void	pipe_time(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nbr_cmd - 1)
	{
		if (pipe(pipex->pipe + (2 * i)) < 0)
			perror("Pipe process fail");
		i++;
	}
}

void	close_pipes(t_pipe *s_pipe)
{
	int	i;

	i = 0;
	while (i < s_pipe->nbr_cmd - 1)
	{
		if (s_pipe->pipe[i] != -1)
		{
			close(s_pipe->pipe[i]);
			s_pipe->pipe[i] = -1;
		}
		i++;
	}
}

int	child_bonus(t_pipe pipex, int i, t_env *env, t_ctrl *minishell)
{
	char	**args;
	char	**envp;
	char	*cmd_path;

	pipex.id[i] = fork();
	if (pipex.id[i] == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		envp = transform_env(*env);
		if (i == 0)
			redirection(pipex.fd1, pipex.pipe[1]);
		else if (i == pipex.nbr_cmd - 1)
			redirection(pipex.pipe[2 * i - 2], pipex.fd2);
		else
			redirection(pipex.pipe[2 * i - 2], \
			pipex.pipe[2 * i + 1]);
		close_pipes(&pipex);
		args = pipex.cmd[i];
		if (built_in(args, env, minishell) == 0)
			return (1);
		if (access(args[0], X_OK) == 0)
			execve(args[0], args, envp);
		cmd_path = p_cmd(envp, args[0]);
		if (!cmd_path)
		{
			fprintf(stderr, "command not found %s\n", args[0]);
			exit(1);
		}
		execve((const char *)cmd_path, args, envp);
		perror("Pipex :");
	}
	return (1);
}

int	pipex(t_cmd *cmd, t_env *env, t_ctrl *minishell)
{
	t_pipe	s_pipe;
	int		i;
	int		j;
	int		wstatus;

	i = 0;
	wstatus = 0;
	s_pipe.fd1 = cmd->input_file;
	s_pipe.fd2 = cmd->output_file;
	s_pipe.cmd = cmd->av;
	s_pipe.nbr_cmd = cmd->ac;
	s_pipe.pipe_nbr = 2 * (cmd->ac - 1);
	s_pipe.env_path = search_env(*env, "PATH");
	if (s_pipe.env_path != NULL)
	{
		s_pipe.cmd_paths = ft_split(s_pipe.env_path, ':');
		if (s_pipe.cmd_paths == NULL)
			return (1);
	}
	s_pipe.pipe = (int *) malloc(sizeof(int) * s_pipe.pipe_nbr); //verif return malloc 
	s_pipe.id = (int *) malloc(sizeof(int) * s_pipe.nbr_cmd);
	pipe_time(&s_pipe);
	while (i < s_pipe.nbr_cmd)
	{
		child_bonus(s_pipe, i, env, minishell);
		i++;
	}
	close_pipes(&s_pipe);
	j = 0;
	close(STDIN_FILENO);
	while (j < s_pipe.nbr_cmd)
	{
		waitpid(s_pipe.id[j], &wstatus, 0);
		j++;
	}
	// free_pipex(&s_pipe);
	return (0);
}
