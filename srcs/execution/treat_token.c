/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:09:50 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 17:12:09 by ldubuche         ###   ########.fr       */
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
		{
			if (i == 0 || i == lexer_size - 1)
			{
				printf("Parse error near '|'\n");
				return (-1);
			}
			pipe_nbr++;
		}
		i++;
	}
	return (pipe_nbr + 1);
}

int	less_great(t_token *token, t_ctrl *ms)
{
	if (token->type == TOKEN_LESS)
	{
		if (less(ms->cmd, ms->lexer->tokens, ms->lexer->pos, ms->lexer->size))
			return (0);
	}
	else if (token->type == TOKEN_GREAT)
	{
		if (great(ms->cmd, ms->lexer->tokens, ms->lexer->pos, ms->lexer->size))
			return (0);
	}
	else if (token->type == TOKEN_DGREAT)
	{
		if (d_great(ms->cmd, ms->lexer->tokens, \
				ms->lexer->pos, ms->lexer->size))
			return (0);
	}
	else if (token->type == TOKEN_DLESS)
	{
		if (d_less(ms->cmd, ms, ms->lexer->pos, ms->lexer->size))
			return (0);
	}
	ms->lexer->pos++;
	return (1);
}

int	deal_with_less_great(t_token *token, t_ctrl *mini)
{
	if (!less_great(token, mini))
		return (1);
	return (0);
}

int	init_treat_token(int *nbr_cmd, t_ctrl *mini, int *j, int *pipe)
{
	*nbr_cmd = 0;
	*nbr_cmd = count_pipe(mini->lexer->tokens, mini->lexer->size);
	if (*nbr_cmd == -1)
		return (0);
	mini->cmd = NULL;
	mini->cmd = malloc_cmd(mini->cmd, *nbr_cmd);
	mini->lexer->pos = 0;
	*j = 0;
	*pipe = 0;
	return (1);
}

int	treat_token(t_ctrl *mini)
{
	int		nbr_cmd;
	t_token	*token;
	int		j;
	int		pipe;

	if (!init_treat_token(&nbr_cmd, mini, &j, &pipe))
		return (0);
	token = NULL;
	while (mini->lexer->pos < mini->lexer->size)
	{
		token = mini->lexer->tokens[mini->lexer->pos];
		if (token->type == TOKEN_WORD && j < nbr_cmd && j == pipe)
			mini->cmd->av[j++] = cmd_suffix(mini->lexer->pos, mini);
		else if (token->type >= TOKEN_LESS && token->type <= TOKEN_DLESS)
		{
			if (deal_with_less_great(token, mini))
				return (0);
		}
		else if (token->type == TOKEN_PIPE)
			pipe++;
		mini->lexer->pos++;
	}
	return (nbr_cmd);
}
