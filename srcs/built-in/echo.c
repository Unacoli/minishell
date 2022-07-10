/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:43:08 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/10 14:30:05 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Fonction echo option -n pour supprimer le retour a la ligne */

int	echo(char **args, int fd)
{
	int	n;

	n = 1;
	while (args[n] && !ft_strncmp("-n", args[n], 3))
		n++;
	while (args[n])
	{
		ft_putstr_fd(args[n], fd);
		if (args[n + 1] != NULL)
			ft_putstr_fd(" ", fd);
		n++;
	}
	if (!args[1] || ft_strncmp("-n", args[1], 3))
		ft_putstr_fd("\n", fd);
	return (0);
}
