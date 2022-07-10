/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/10 04:09:37 by nargouse         ###   ########.fr       */
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

int	choose_execve(int nbr_cmd, t_ctrl *minishell)
{
	if (nbr_cmd == 1)
		return (simple_execve(minishell->cmd, *(minishell->env), minishell));
	else
		return (pipex(minishell->cmd, minishell->env, minishell));
}

static int	ft_execution(t_ctrl *mini)
{
	int		nbr_cmd;
	t_token	*token;
	int		j;

	nbr_cmd = count_pipe(mini->lexer->tokens, mini->lexer->size);
	mini->cmd = malloc_cmd(mini->cmd, nbr_cmd);
	mini->lexer->pos = 0;
	token = NULL;
	j = 0;
	while (mini->lexer->pos < mini->lexer->size)
	{
		token = mini->lexer->tokens[mini->lexer->pos];
		if (token->type == TOKEN_WORD)
			mini->cmd->av[j++] = cmd_suffix(mini->lexer->pos, mini);
		else if (token->type >= TOKEN_LESS && token->type <= TOKEN_DLESS)
		{
			if (less_great(token, mini))
				return (1);
		}
		else if (token->type == TOKEN_PIPE)
		{
			if (mini->lexer->pos == 0 || mini->lexer->pos == mini->lexer->size - 1)
				return (printf("Parse error near '|'\n"));
		}
		mini->lexer->pos++;
	}
	return (choose_execve(nbr_cmd, mini));
}

void	ft_input(t_ctrl *minishell)
{
	int	cmd;

	cmd = ft_command(minishell);
	if (cmd != -1)
		ft_execution(minishell);
}
