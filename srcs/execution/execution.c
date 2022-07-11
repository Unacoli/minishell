/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:08:20 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/11 03:28:44 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd(t_cmd *cmd)
{
	if (cmd->input_file != 0 && cmd->input_file != -1)
	{
		close(cmd->input_file);
		cmd->input_file = -1;
	}
	if (cmd->output_file != 1 && cmd->output_file != -1)
	{
		close(cmd->output_file);
		cmd->output_file = -1;
	}
}

//add un gestion de la valeur de retour avec WIFEXITED et WIFSIGNALED a la fin

void	choose_execve(int nbr_cmd, t_ctrl *minishell)
{
	minishell->status = 0;
	printf("%d\n", nbr_cmd);
	if (nbr_cmd == 1)
	{
		if (built_in(minishell->cmd->av[0], minishell->env, minishell) != 0)
			simple_execve(minishell->cmd, *(minishell->env));
	}
	else
		pipex(minishell->cmd, minishell->env, minishell);
	signal_handler();
	free_cmd(minishell->cmd);
}
