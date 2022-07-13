/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:00:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 21:03:16 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in(char **arg, t_env *env, t_ctrl *minishell, int fd)
{
	if (ft_strncmp(arg[0], "cd", 2) == 0)
		cd(env, arg);
	else if (ft_strncmp(arg[0], "exit", 4) == 0)
	{
		if (arg[1])
			g_status = ft_atoi(arg[1]);
		exit_free(minishell);
	}
	else if (ft_strncmp(arg[0], "echo", 4) == 0)
		echo(arg, fd);
	else if (ft_strncmp(arg[0], "env", 3) == 0)
		envi(env, fd);
	else if (ft_strncmp(arg[0], "export", 6) == 0)
		exporti(env, arg, fd);
	else if (ft_strncmp(arg[0], "pwd", 3) == 0)
		pwd(fd);
	else if (ft_strncmp(arg[0], "unset", 5) == 0)
		unset(&(minishell->env), arg);
	else
		return (1);
	return (0);
}
