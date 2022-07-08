/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 03:02:37 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/08 05:00:10 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*malloc_cmd(t_cmd *cmd, size_t nbr_cmd)
{
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->input_file = 1;
	cmd->output_file = 0;
	cmd->av = malloc(sizeof(char **));
	if (!cmd->av)
		return (NULL);
	cmd->ac = 0;
	(void)nbr_cmd;
	return (cmd);
}
