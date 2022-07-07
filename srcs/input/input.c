/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:36:50 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/07 04:20:43 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_cmd(size_t pos, t_ctrl *minishell)
{
	char	**arg;
	int		i;

	i = 0;
	arg = malloc(sizeof(char **));
	while (pos < minishell->lexer->size
			&& minishell->lexer->tokens[pos]->type == TOKEN_WORD)
	{
		arg[i] = ft_strdup(minishell->lexer->tokens[pos]->str);
		i++;
		pos++;
	}
	built_in(arg, minishell->env, minishell);
	return (pos);
}

static int	ft_execution(t_ctrl *minishell)
{
	t_token	*token;

	minishell->lexer->pos = 0;
	while (minishell->lexer->pos < minishell->lexer->size)
	{
		token = minishell->lexer->tokens[minishell->lexer->pos];
		if (token->type == TOKEN_WORD)
			minishell->lexer->pos = exec_cmd(minishell->lexer->pos, minishell);
//		else if (token->type == TOKEN_LESS)
//			exec_cmd();
//		else if (token->type == TOKEN_GREAT)
//			exec_cmd();
//		else if (token->type == TOKEN_DGREAT)
//			great(
//		else if (token->type == TOKEN_DLESS)
//		{
//			if (minishell->lexer->pos == 0)
//				here_doc("END", env);
		else if (token->type == TOKEN_PIPE)
		{
			if (minishell->lexer->pos == 0)
				return (printf("Parse error near '|'\n"));
		}
		minishell->lexer->pos++;
	}
	return (0);
}

void	ft_input(t_ctrl *minishell)
{
	int	cmd;

	cmd = ft_command(minishell);
	if (cmd != -1)
		ft_execution(minishell);
}
