/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:59:55 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/13 10:55:28 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_ctrl	minishell;

	if (ac != 0)
	{
		printf("Usage : %s\n", av[0]);
		exit(EXIT_SUCCESS);
	}
	init_shell(&minishell);
	choose_env(env);
	return (running_shell(&minishell));
}
