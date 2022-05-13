/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:43:08 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/13 14:32:21 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Fonction echo option -n pour supprimer le retour a la ligne
	Potentiel risque que printf ne flush pas sans retour a la ligne */

void	echo(char **args)
{
	int	n;

	n = 0;
	if (!ft_strncmp("-n", args[0], 3))
		n = 1;
	while (args[n])
	{
		printf("%s", args[n]);
		if (args[n + 1] != NULL)
			printf(" ");
	}
	if (ft_strncmp("-n", args[0], 3))
		printf("\n");
}
