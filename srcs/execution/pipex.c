/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:28:29 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/09 15:53:14 by ldubuche         ###   ########.fr       */
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

void	redirection(int fd_0, int fd_1)
{
	// fprintf(stderr, "redirige %d dans 0 et %d dans 1\n", fd_0, fd_1);
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

	if (ft_strncmp(pipex.cmd[i][0], "exit", ft_strlen(pipex.cmd[i][0])) == 0)
		exit_shell(minishell);
	pipex.id = fork();
	if (pipex.id == 0)
	{
		envp = transform_env(*env);
		if (i == 0)
			redirection(pipex.fd1, pipex.pipe[1]);
		else if (i == pipex.nbr_cmd - 1)
		{
			// fprintf(stderr, "i = %d", 2 * i - 2);
			redirection(pipex.pipe[2 * i - 2], pipex.fd2);
		}
		else
		{
			// fprintf(stderr, "i = %d, i = %d", 2 * i - 2, 2 * i + 1);
			redirection(pipex.pipe[2 * i - 2], \
			pipex.pipe[2 * i + 1]);
		}
		close_pipes(&pipex);
		// if (i != 0)
		// {
		// 	char *buff=malloc(sizeof(char *) * 201);
		// 	int i= read(0, buff, 200);
		// 	buff[i] = '\0';
		// 	fprintf(stdout, "OUTPUT of the pipe .%s.\n", buff);
		// }
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

	i = 0;
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
	pipe_time(&s_pipe);
	while (i < s_pipe.nbr_cmd)
	{
		child_bonus(s_pipe, i, env, minishell);
		i++;
	}
	close_pipes(&s_pipe);
	waitpid(-1, NULL, 0);
	//free_pipex(&s_pipe);
	return (0);
}
