/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:00:27 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/02 10:28:44 by ldubuche         ###   ########.fr       */
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

# include "ast.h"
# include "built_in.h"
# include "environnement.h"
# include "execution.h"
# include "exiting.h"
# include "handle_input.h"
# include "parsing.h"

/*Struct for controller*/

typedef struct s_ctrl
{
	t_lexer	*lexer;
	t_ast	*ast;
	t_cmd	*cmd;
	t_env	*env;
}				t_ctrl;

/*Functions for main, starting minishell*/

void	init_shell(t_ctrl *minishell);
t_env	*choose_env(char **env);
int		running_shell(t_ctrl *minishell);

/*Old functions, WIP to sort this*/

void	lexe(char *cmd, t_env *envi);
void	freeenv(t_env *un);
void	exed(char *cmd, t_env *envi);
void	freetr(char	**pa, char *name, int i);
char	*getna(char *cmd);
void	child(char *path, char **argv, char**env, char *name);
void	coredump(int sig);
void	childctrlc(int sig);
void	freetab(char **tab);

#endif
