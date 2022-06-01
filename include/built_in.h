/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:47:06 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/01 18:48:02 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

/* BUILT-IN functions */
int		cd(t_env env, char **args);
void	echo(char **args);
char	*envi(t_env env);
void	exit_free(t_ctrl *minishell);
int		export(t_env *env, char **args);
void	pwd(void);
int		unset(t_env *env, char **args);
	//utils
char	*find_key(char *arg);
char	*next_lower(t_env env, char *previous);
char	*first_lower(t_env env);
int		non_valid_identifier(char *arg, char *function);


#endif