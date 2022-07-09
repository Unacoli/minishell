/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/09 07:11:19 by nargouse         ###   ########.fr       */
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
		{
			minishell->cmd->av[j] = cmd_suffix(minishell->lexer->pos, minishell);
			j++;
		}
		else if (token->type == TOKEN_LESS)
		{
			if (!less(minishell->cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 1;
			else
				return (1);
		}
		else if (token->type == TOKEN_GREAT)
		{
			if (!great(minishell->cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 1;
			else
				return (1);
		}
		else if (token->type == TOKEN_DGREAT)
		{
			if (!d_great(minishell->cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 1;
			else
				return (1);
		}
		else if (token->type == TOKEN_DLESS)
		{
			if (!d_less(minishell->cmd, minishell, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 1;
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
	if (minishell->cmd->input_file == -1)
		minishell->cmd->input_file = open("/dev/stdin", O_RDONLY);
	if (minishell->cmd->output_file == -1)
		minishell->cmd->output_file = open("/dev/stdout", O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (nbr_cmd == 1)
		simple_execve(minishell->cmd, *(minishell->env), minishell);
	else
		pipex(minishell->cmd, minishell->env, minishell);
	return (0);
}

void	ft_input(t_ctrl *minishell)
{
	int	cmd;

	cmd = ft_command(minishell);
	if (cmd != -1)
		ft_execution(minishell);
}
