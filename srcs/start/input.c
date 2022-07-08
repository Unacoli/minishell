/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/08 05:02:51 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	exec_cmd(size_t pos, t_ctrl *minishell)
// {
// 	char	**arg;
// 	int		i;

// 	i = 0;
// 	arg = malloc(sizeof(char **));
// 	while (pos < minishell->lexer->size
// 			&& minishell->lexer->tokens[pos]->type == TOKEN_WORD)
// 	{
// 		arg[i] = ft_strdup(minishell->lexer->tokens[pos]->str);
// 		i++;
// 		pos++;
// 	}
// 	built_in(arg, minishell->env, minishell);
// 	return (pos);
// }

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

static int	ft_execution(t_ctrl *minishell)
{
	size_t	nbr_cmd;
	t_token	*token;

	nbr_cmd = count_pipe(minishell->lexer->tokens, minishell->lexer->size);
	minishell->cmd = malloc_cmd(minishell->cmd, nbr_cmd);
	minishell->lexer->pos = 0;
	token = NULL;
	while (minishell->lexer->pos < minishell->lexer->size)
	{
		token = minishell->lexer->tokens[minishell->lexer->pos];
		if (token->type == TOKEN_WORD)
			minishell->cmd = simple_cmd(minishell->lexer->pos, minishell, minishell->cmd);
		else if (token->type == TOKEN_LESS)
		{
			if (!less(minishell->cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 2;
			else
				return (1);
		}
		else if (token->type == TOKEN_GREAT)
		{
			if (!great(minishell->cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 2;
			else
				return (1);
		}
		else if (token->type == TOKEN_DGREAT)
		{
			if (!less(minishell->cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 2;
			else
				return (1);
		}
		else if (token->type == TOKEN_DLESS)
		{
			if (!d_less(minishell->cmd, minishell, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 2;
			else
				return (1);
		}
		else if (token->type == TOKEN_PIPE)
		{
			if (minishell->lexer->pos == 0 || minishell->lexer->pos == minishell->lexer->size - 1)
				return (printf("Parse error near '|'\n"));
		}
		minishell->lexer->pos++;
	}
	if (nbr_cmd == 1)
		simple_execve(minishell->cmd, minishell->env, minishell);
	else
		pipex(minishell->cmd, minishell->env, minishell, nbr_cmd);
	return (0);
}

void	ft_input(t_ctrl *minishell)
{
	int	cmd;

	cmd = ft_command(minishell);
	if (cmd != -1)
		ft_execution(minishell);
}
