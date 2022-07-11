/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 03:02:37 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/11 00:17:50 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*malloc_cmd(t_cmd *cmd, size_t nbr_cmd)
{
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->input_file = 0;
	cmd->output_file = 1;
	cmd->av = NULL;
	cmd->av = (char ***) malloc(sizeof(char **) * (nbr_cmd + 1));
	if (!cmd->av)
		return (NULL);
	cmd->av[nbr_cmd] = NULL;
	cmd->ac = nbr_cmd;
	return (cmd);
}
