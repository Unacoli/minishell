/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:06:26 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/13 02:15:42 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	default_env(void)
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

void	init_shell(t_ctrl minishell)
{
	minishell->lexer = NULL;
	minishell->ast = NULL;
	minishell->cmd = NULL;
}

void	choose_env(char **env)
{
	if (!(*env))
		default_env();
	else
		/*create a function who load the existing env*/
	signal_handler();
}

int	running_shell(t_ctrl *minishell)
{
	while (1)
		input(minishell);
	/*free all if minishell stop*/
	return (0);
}
