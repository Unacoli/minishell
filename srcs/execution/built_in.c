/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:00:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/10 14:24:14 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in(char **arg, t_env *env, t_ctrl *minishell)
{
	if (ft_strncmp(arg[0], "cd", ft_strlen(arg[0])) == 0)
		cd(env, arg);
	else if (ft_strncmp(arg[0], "exit", ft_strlen(arg[0])) == 0)
		exit_shell(minishell);
	else if (ft_strncmp(arg[0], "echo", ft_strlen(arg[0])) == 0)
		echo(arg, minishell->cmd->output_file);
	else if (ft_strncmp(arg[0], "env", ft_strlen(arg[0])) == 0)
		envi(env, minishell->cmd->output_file);
	else if (ft_strncmp(arg[0], "export", ft_strlen(arg[0])) == 0)
		exporti(env, arg, minishell->cmd->output_file);
	else if (ft_strncmp(arg[0], "pwd", ft_strlen(arg[0])) == 0)
		pwd(minishell->cmd->output_file);
	else if (ft_strncmp(arg[0], "unset", ft_strlen(arg[0])) == 0)
		unset(env, arg);
	else
		return (1);
	return (0);
}
