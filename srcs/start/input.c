/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/09 17:47:03 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	count_pipe(t_token **tokens, size_t lexer_size)
{
	size_t	i;
	size_t	pipe_nbr;

	i = 0;
	pipe_nbr = 0;
	while (i < lexer_size)
	{
		if (tokens[i]->type == TOKEN_PIPE)
			pipe_nbr++;
		i++;
	}
	return (pipe_nbr + 1);
}

int choose_execve(int nbr_cmd, t_ctrl *minishell)
{
	if (nbr_cmd == 1)
		return (simple_execve(minishell->cmd, *(minishell->env), minishell));
	else
		return (pipex(minishell->cmd, minishell->env, minishell));
}

static int	ft_execution(t_ctrl *minishell)
{
	int		nbr_cmd;
	t_token	*token;
	int		j;

	nbr_cmd = count_pipe(minishell->lexer->tokens, minishell->lexer->size);
	minishell->cmd = malloc_cmd(minishell->cmd, nbr_cmd);
	minishell->lexer->pos = 0;
	token = NULL;
	j = 0;
	while (minishell->lexer->pos < minishell->lexer->size)
	{
		token = minishell->lexer->tokens[minishell->lexer->pos];
		if (token->type == TOKEN_WORD)
			minishell->cmd->av[j++] = cmd_suffix(minishell->lexer->pos, minishell);
		else if (token->type >= TOKEN_LESS && token->type <= TOKEN_DLESS)
		{
			if(less_great(token, minishell))
				return (1);
		}
		else if (token->type == TOKEN_PIPE)
		{
			if (minishell->lexer->pos == 0 || minishell->lexer->pos == minishell->lexer->size - 1)
				return (printf("Parse error near '|'\n"));
		}
		minishell->lexer->pos++;
	}
	return (choose_execve(nbr_cmd, minishell));
}

void	ft_input(t_ctrl *minishell)
{
	int	cmd;

	cmd = ft_command(minishell);
	if (cmd != -1)
		ft_execution(minishell);
}
