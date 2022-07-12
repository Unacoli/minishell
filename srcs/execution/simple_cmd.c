/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:35:00 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/12 14:16:24 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*finish_substi(char *to_treat, t_env *env)
{
	char	*str;

	if (to_treat[0] == SINGLE_QUOTE || to_treat[0] == DOUBLE_QUOTE)
	{
		if (to_treat[0] == DOUBLE_QUOTE)
		{
			str = search_substi(env, to_treat);
			str = delete_quote(str);
		}
		else
			str = delete_quote(to_treat);
	}
	else
	{
		str = ft_strdup(to_treat);
	}
	return (str);
}

void	find_arg(t_ctrl *minishell, int *pos, int *i)
{
	if (minishell->lexer->tokens[pos]->type >= TOKEN_LESS \
		&& minishell->lexer->tokens[pos]->type <= TOKEN_DLESS)
		*pos += 2;
	else
	{
		arg[i] = finish_substi(minishell->lexer->tokens[pos]->str, \
		minishell->env);
		*pos++;
		*i++;
	}
}

char	**cmd_suffix(size_t pos, t_ctrl *minishell)
{
	char	**arg;
	int		i;

	i = pos;
	while (pos < minishell->lexer->size
		&& minishell->lexer->tokens[pos]->type != TOKEN_PIPE)
		pos++;
	arg = (char **) malloc(sizeof(char *) * ((pos - i) + 1));
	pos = i;
	i = 0;
	while (pos < minishell->lexer->size
		&& minishell->lexer->tokens[pos]->type != TOKEN_PIPE)
	{
		find_arg();
	}
	arg[i] = NULL;
	minishell->lexer->pos += i - 1;
	return (arg);
}
