/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:41:58 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 05:40:06 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Juste un debut a partir des structures, il y aura problement besoin de 
	la modifier*/

static void	free_command(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (cmd->av)
	{	
		while (cmd->av[i])
		{
			j = 0;
			while (cmd->av[i][j])
			{
				if (cmd->av[i][j] != NULL)
					free(cmd->av[i][j]);
				j++;
			}
			if (cmd->av[i] != NULL)
				free(cmd->av[i]);
			i++;
		}
		free(cmd->av);
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		free_command(cmd);
		free(cmd);
	}
}
