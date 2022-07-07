/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:00:27 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/07 01:22:04 by nargouse         ###   ########.fr       */
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

# include "parsing.h"
# include "ast.h"
# include "environnement.h"
# include "execution.h"
# include "controller.h"
# include "exiting.h"
# include "handle_input.h"
# include "built_in.h"

/*Functions for main, starting minishell*/

void	init_shell(t_ctrl *minishell);
t_env	*choose_env(char **env);
int		running_shell(t_ctrl *minishell);

/*Built-in functions*/

int	built_in(char **arg, t_env *emv, t_ctrl *minishell);

#endif
