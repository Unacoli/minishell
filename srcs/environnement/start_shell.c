/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:06:26 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/18 11:27:07 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*default_env(void)
{
	g_env = ft_calloc(4, sizeof(char *));
	if (!g_env)
	{
		printf("Malloc error\n");
		exit(EXIT_FAILURE);
	}
	/*Create a function for setting the working directory*/
	/*Function for putting environnement with shell level and shell path*/
}

void	init_shell(t_ctrl *minishell)
{
	minishell->lexer = NULL;
	minishell->ast = NULL;
	minishell->cmd = NULL;
	minishell->env = NULL;
}

void	choose_env(char **env)
{
	t_env	*struc_env;

	if (!(*env))
		struc_env = default_env();
	else
		struc_env = init_env(env);
	signal_handler();
}

int	running_shell(t_ctrl *minishell)
{
	while (1)
		input(minishell);
	/*free all if minishell stop*/
	return (0);
}
