/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:59:55 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/29 13:57:46 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	char	*cmd;

	(void) ac;
	(void) av;
	while (1)
	{
		cmd = readline("minishell% ");
		if (ft_strncmp(cmd, "exit", 10) == 0)
			exit(0);
	}
	return (0);
}
