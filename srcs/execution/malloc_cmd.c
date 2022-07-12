/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 03:02:37 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/12 20:58:37 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*malloc_cmd(t_cmd *cmd, size_t nbr_cmd)
{
	size_t	i;

	i = 0;
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->input_file = 0;
	cmd->output_file = 1;
	cmd->av = NULL;
	cmd->av = (char ***) malloc(sizeof(char **) * (nbr_cmd + 1));
	if (!cmd->av)
		return (NULL);
	while (i <= nbr_cmd)
	{
		cmd->av[i] = NULL;
		i++;
	}
	cmd->ac = nbr_cmd;
	return (cmd);
}
