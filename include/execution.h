/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:50:19 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 18:04:28 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <string.h>

/*Structs for execution*/

typedef struct s_cmd
{
	size_t	ac;
	char	***av;
	int		input_file;
	int		output_file;
}				t_cmd;

typedef struct s_pipe
{
	int		fd1;
	int		fd2;
	int		pipe_nbr;
	int		nbr_cmd;
	char	*env_path;
	char	***cmd;
	int		*pipe;
	int		*id;
}	t_pipe;

/* Substitution functions */

char	*make_3_str(char *str, int position, int j, char *value);
char	*join_3_str(char *before, char *substi, char *after);

/* Built-in functions*/

char	*p_cmd(char **envp, char *cmd);
void	redirection(int fd_0, int fd_1);

/*Malloc functions*/

t_cmd	*malloc_cmd(t_cmd *cmd, size_t nbr_cmd);
void	signal_handler_exec(void);
void	close_fd(t_cmd *cmd);
void	pipe_time(t_pipe *pipex);
void	close_pipes(t_pipe *s_pipe);
int		status_handler(int wstatus);

#endif
