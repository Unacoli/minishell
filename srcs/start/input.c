/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/07 18:24:04 by ldubuche         ###   ########.fr       */
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

int	compte_pipe(t_token **tokens, int lexer_size)
{
	int	i;
	int	pipe_nbr;

	i = 0;
	pipe_nbr = 0;
	while (i < lexer_size)
	{
		if (tokens[i]->type == TOKEN_PIPE)
			pipe_nbr ++;
		i++;
	}
	return (pipe_nbr + 1);
}

static int	ft_execution(t_ctrl *minishell)
{
	t_token	*token;
	t_cmd	cmd;
	int j;
	
	cmd.input = 1;
	cmd.output = 0;
	cmd.nbr_cmd = compte_pipe(minishell->lexer->tokens, minishell->lexer->size);
	cmd.cmds = (char ***) malloc(sizeof(char **) * cmd.nbr_cmd); //verif retour malloc
	j = 0;
	minishell->lexer->pos = 0;
	while (minishell->lexer->pos < minishell->lexer->size)
	{
		token = minishell->lexer->tokens[minishell->lexer->pos];
		if (token->type == TOKEN_WORD)
		{
			cmd.cmds[j] = cmd_suffix(minishell->lexer->pos, minishell);
			j++;
		}
		else if (token->type == TOKEN_LESS)
		{
			if (!less(&cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 2;
			else
				return (1);
		}
		else if (token->type == TOKEN_GREAT)
		{
			if (!great(&cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 2;
			else
				return (1);
		}
		else if (token->type == TOKEN_DGREAT)
		{
			if (!less(&cmd, minishell->lexer->tokens, minishell->lexer->pos, minishell->lexer->size))
				minishell->lexer->pos += 2;
			else
				return (1);
		}
		else if (token->type == TOKEN_DLESS)
		{
			if (!d_less(&cmd, minishell, minishell->lexer->pos, minishell->lexer->size))
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
	if(cmd.nbr_cmd == 1)
		simple_execve(&cmd, *(minishell->env), minishell);
	else
		pipex(&cmd, minishell->env, minishell);
	return (0);
}

void	ft_input(t_ctrl *minishell)
{
	int	cmd;

	cmd = ft_command(minishell);
	if (cmd != -1)
		ft_execution(minishell);
}
