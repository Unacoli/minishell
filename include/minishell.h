/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:00:27 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/31 17:11:52 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/include/libft.h"
# include <signal.h>

typedef struct s_env	t_env;
void	parsing(char *cmd, t_env *enviro);
void	ctrlc(int i);
char	*pwd(void);
char	*envi( t_env *enviro);
char	*ft_strjoinchar(char const *s1, char const s2);
t_env	*initenv(char **env);
char	*export(char *cmd, t_env *un);
void	changedeb(t_env *un);
void	unset(char *cmd, t_env *un);
char	*cd(char	*cmd);
char	*echo(char	*cmd, t_env *enviro, int tiretn);
char	*getvale(char *name, t_env *un);


struct s_env
{
	t_env	*deb;
	char	*name;
	char	*value;
	t_env	*next;
};

#endif
