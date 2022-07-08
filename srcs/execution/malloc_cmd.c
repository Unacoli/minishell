/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 03:02:37 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/08 16:09:58 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*malloc_cmd(t_cmd *cmd, size_t nbr_cmd)
{
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->input_file = -1;
	cmd->output_file = -1;
	cmd->av = malloc(sizeof(char ***) * (nbr_cmd + 1));
	if (!cmd->av)
		return (NULL);
	cmd->ac = nbr_cmd;
	return (cmd);
}
