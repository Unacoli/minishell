/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:59:55 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/06 23:50:44 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_ctrl	minishell;

	if (ac != 1)
	{
		printf("Usage : %s\n", av[0]);
		exit(EXIT_SUCCESS);
	}
	init_shell(&minishell);
	minishell.env = choose_env(env);
	if (minishell.env == NULL)
		exit_free(&minishell);
	return (running_shell(&minishell));
}
