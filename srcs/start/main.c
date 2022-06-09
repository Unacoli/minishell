/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:59:55 by nargouse          #+#    #+#             */
<<<<<<< HEAD:srcs/main.c
/*   Updated: 2022/06/03 11:41:38 by ldubuche         ###   ########.fr       */
=======
/*   Updated: 2022/06/09 04:28:13 by nargouse         ###   ########.fr       */
>>>>>>> 68a751c33ccdd5fd4ee39cbcb8865f66a9181880:srcs/start/main.c
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
