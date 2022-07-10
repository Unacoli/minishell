/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:50:19 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/10 04:41:56 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <string.h>
# include "environnement.h"

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
	char	**cmd_paths;
	char	***cmd;
	int		*pipe;
	int		id;
}	t_pipe;

typedef struct s_ctrl
{
	t_lexer	*lexer;
	t_cmd	*cmd;
	t_env	*env;
}				t_ctrl;

/* Substitution functions */

char	*search_substi(t_env *env, char *str);
char	*substitution(char *str, int position, t_env *env);
char	*make_3_str(char *str, int position, int j, char *value);
char	*join_3_str(char *before, char *substi, char *after);

/* Built-in functions*/

int		simple_execve(t_cmd *cmd, t_env env, t_ctrl *minishell);
char	**transform_env(t_env env);
char	*p_cmd(char **envp, char *cmd);
void	redirection(int fd_0, int fd_1);
t_cmd	*simple_cmd(size_t pos, t_ctrl *minishell, t_cmd *cmd);
int		d_great(t_cmd *cmd, t_token **tokens, int pos, int lexer_size);
int		great(t_cmd *cmd, t_token **tokens, int pos, int lexer_size);
int		less(t_cmd *cmd, t_token **tokens, int pos, int lexer_size);
int		d_less(t_cmd *cmd, t_ctrl *minishell, int pos, int lexer_size);
int		pipex(t_cmd *cmd, t_env *env, t_ctrl *minishell);
char	**cmd_suffix(size_t pos, t_ctrl *minishell);

/*Malloc functions*/

t_cmd	*malloc_cmd(t_cmd *cmd, size_t nbr_cmd);
int		less_great(t_token *token, t_ctrl *minishell);

#endif
