/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:43:08 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/07 12:50:33 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Fonction echo option -n pour supprimer le retour a la ligne */

int	echo(char **args)
{
	int	n;

	n = 1;
	if (!ft_strncmp("-n", args[1], 3))
		n = 2;
	while (args[n])
	{
		ft_putstr(args[n]);
		if (args[n + 1] != NULL)
			ft_putstr(" ");
		n++;
	}
	if (ft_strncmp("-n", args[1], 3))
		printf("\n");
	return (0);
}
