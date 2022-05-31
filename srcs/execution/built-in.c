/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:00:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/31 16:21:24 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in(char **cmd_arg, t_ctrl *minishell)
{
	char	*cmd;

	cmd = cmd_arg[0];
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		return (cd(minishell->env, cmd_arg + 1));
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		return (echo(cmd_arg + 1));
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		return (envi(minishell->env));
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		return (exit_free(minishell));
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		return (export(minishell->env, cmd_arg + 1));
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		return (pwd());
	if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0)
		return (unset(minishell->env, cmd_arg + 1));
	else
		return (call_exceve(env, cmd_arg));
}