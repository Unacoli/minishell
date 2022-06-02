/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:47:06 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 11:57:42 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

/*	BUILT-IN functions */
int		cd(t_ctrl *minishell, char **args);
int		echo(char **args);
int		envi(t_ctrl *minishell);
void	exit_free(t_ctrl *minishell, int ret);
int		export(t_ctrl *minishell, char **args);
int		pwd(void);
int		unset(t_ctrl *minishell, char **args);

/*	Utils to find key in env and to sort env in alphabetical order */
char	*find_key(char *arg);
char	*next_lower(t_env env, char *previous);
char	*first_lower(t_env env);
int		non_valid_identifier(char *arg, char *function);

#endif