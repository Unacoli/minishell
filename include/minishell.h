/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:00:27 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/12 21:40:11 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/include/libft.h"
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define _GNU_SOURCE 
# include <unistd.h>
# include <sys/syscall.h>

# include "parsing.h"
# include "environnement.h"
# include "execution.h"
# include "exiting.h"
# include "built_in.h"

extern int	g_status;

typedef struct s_ctrl
{
	t_lexer	*lexer;
	t_cmd	*cmd;
	t_env	*env;
}				t_ctrl;

/*Functions for main, starting minishell*/

void	init_shell(t_ctrl *minishell);
int		running_shell(t_ctrl *minishell);

void	ft_input(t_ctrl *minishell);
int		ft_command(t_ctrl *minishell);

/*Signal handler*/

void	signal_handler(void);
void	error(int signal);

int		built_in(char **arg, t_env *env, t_ctrl *minishell, int fd);
int		simple_execve(t_cmd *cmd, t_env *env, t_ctrl *minishell);
int		d_less(t_cmd *cmd, t_ctrl *minishell, int pos, int lexer_size);
int		pipex(t_cmd *cmd, t_env *env, t_ctrl *minishell);
char	**cmd_suffix(size_t pos, t_ctrl *minishell);
int		less_great(t_token *token, t_ctrl *minishell);
void	choose_execve(int nbr_cmd, t_ctrl *minishell);
t_cmd	*simple_cmd(size_t pos, t_ctrl *minishell, t_cmd *cmd);
int		treat_token(t_ctrl *mini);

void	exit_free(t_ctrl *minishell);
void	error_exit(char *str, t_ctrl *minishell, char **envp);

#endif