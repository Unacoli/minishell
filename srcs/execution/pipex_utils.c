/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:16:35 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/11 17:25:29 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	status_handler(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	if (WIFSIGNALED(wstatus))
		return (128 + WTERMSIG(wstatus));
	return (wstatus);
}

int	init_pipex(t_pipe *s_pipe, t_cmd *cmd, t_env *env)
{
	s_pipe->fd1 = cmd->input_file;
	s_pipe->fd2 = cmd->output_file;
	s_pipe->cmd = cmd->av;
	s_pipe->nbr_cmd = cmd->ac;
	s_pipe->pipe_nbr = 2 * (cmd->ac - 1);
	s_pipe->env_path = search_env(*env, "PATH");
	if (s_pipe->env_path != NULL)
	{
		s_pipe->cmd_paths = ft_split(s_pipe->env_path, ':');
		if (s_pipe->cmd_paths == NULL)
			return (1);
	}
	return (0);
}

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
	while (i < s_pipe->pipe_nbr)
	{
		if (s_pipe->pipe[i] != -1)
		{
			close(s_pipe->pipe[i]);
			s_pipe->pipe[i] = -1;
		}
		i++;
	}
}
