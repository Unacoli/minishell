/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:47:06 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 14:36:32 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

/*	BUILT-IN functions */
int		cd(t_env *env, char **args);
int		echo(char **args);
int		envi(t_env env);
void	exit_free(t_ctrl *minishell);
int		export(t_env *env, char **args);
int		pwd(void);
int		unset(t_env *env, char **args);

/*	Utils to find key in env and to sort env in alphabetical order */
char	*find_key(char *arg);
char	*next_lower(t_env env, char *previous);
char	*first_lower(t_env env);
int		non_valid_identifier(char *arg, char *function);
char	*get_pwd(void);

#endif
