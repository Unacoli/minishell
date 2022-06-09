/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:41:58 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/09 15:07:41 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Juste un debut a partir des structures, il y aura problement besoin de 
	la modifier*/

static void	free_simple_command(t_simplecmd *splcmd)
{
	int	i;

	i = 0;
	if (splcmd)
	{
		if (splcmd->av)
		{
			while (splcmd->av[i] != NULL)
			{
				free(splcmd->av[i]);
				i++;
			}
			free(splcmd->av);
		}
		free(splcmd);
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->simple_cmd)
		{
			cmd->cmd_count = 0;
			while (cmd->cmd_count < cmd->cap)
			{
				free_simple_command(cmd->simple_cmd[cmd->cmd_count]);
				cmd->cmd_count++;
			}
			free(cmd->simple_cmd);
		}
		free(cmd);
	}
}
