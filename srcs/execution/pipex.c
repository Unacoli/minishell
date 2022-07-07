/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:28:29 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/07 02:09:34 by nargouse         ###   ########.fr       */
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
static void	redirection(int fd_0, int fd_1)
{
	dup2(fd_0, 0);
	dup2(fd_1, 1);
}

void	pipe_time(t_pipe *s_pipe)
{
	if (pipe(s_pipe->pipe) < 0)
		printf("Pipe process fail\n");
}

void	close_pipes(t_pipe *s_pipe)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (s_pipe->pipe[i] != -1)
		{
			close(s_pipe->pipe[i]);
			s_pipe->pipe[i] = -1;
		}
		i++;
	}
}

void	child_bonus(t_pipe pipex, int i, t_env *env)
{
	char	**args;

	pipex.id = fork();
	if (pipex.id == 0)
	{
		if (i == 0)
		{
			close(pipex.pipe[0]);
			redirection(pipex.fd1, pipex.pipe[1]);
			close(pipex.pipe[1]);
		}
		else if (i == 1)
		{
			close(pipex.pipe[1]);
			redirection(pipex.pipe[0], pipex.fd2);
			close(pipex.pipe[0]);
		}
		args = ft_split(pipex.cmd[i], ' ');
		i ++;
		if (args == NULL)
			printf("ft_Split fail");
		call_execve(args, *env);
	}
}

int	pipex(t_cmd *cmd, t_env *env)
{
	t_pipe	s_pipe;
	int		i;

	i = 0;
	s_pipe.fd1 = cmd->input;
	s_pipe.fd2 = cmd->output;
	s_pipe.cmd = cmd->cmds;
	s_pipe.env_path = search_env(*env, "PATH");
	if (s_pipe.env_path != NULL)
	{
		s_pipe.cmd_paths = ft_split(s_pipe.env_path, ':');
		if (s_pipe.cmd_paths == NULL)
			return (1);
	}
	s_pipe.pipe = (int *) malloc(sizeof(int) * 2);
	pipe_time(&s_pipe);
	while (i < 2)
	{
		child_bonus(s_pipe, i, env);
		i++;
	}
	close_pipes(&s_pipe);
	waitpid(-1, NULL, 0);
	//free_pipex(&s_pipe);
	return (0);
}

//int main(int argc, char **argv, char **envp)
//{
//	t_env	*env;
//	t_cmd	cmd;
//
//	(void) argc;
//	env = init_env(envp);
//	cmd.input = open("built-in.c", O_RDONLY);
//	cmd.output = open("output_file", O_CREAT | O_RDWR | O_TRUNC, 0000644);
//	cmd.cmds = argv + 1;
//	pipex(&cmd, env);
//	return (0);
//}
