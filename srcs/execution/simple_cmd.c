/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:35:00 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 16:57:42 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*finish_substi(char *to_treat, t_env *env)
{
	char	*str;
	int		i;

	i = 0;
	if (to_treat[0] == SINGLE_QUOTE || to_treat[0] == DOUBLE_QUOTE)
	{
		if (to_treat[0] == DOUBLE_QUOTE)
		{
			str = search_substi(env, to_treat);
			if (ft_strncmp(str, to_treat, ft_strlen(to_treat)) == 0)
				i = 1;
			str = delete_quote(str, i);
		}
		else
		{
			i = 1;
			str = delete_quote(to_treat, i);
		}
	}
	else
	{
		str = ft_strdup(to_treat);
	}
	return (str);
}

void	find_arg(t_ctrl *minishell, size_t *pos, int *i, char **arg)
{
	if (minishell->lexer->tokens[*pos]->type >= TOKEN_LESS \
		&& minishell->lexer->tokens[*pos]->type <= TOKEN_DLESS)
		*pos += 2;
	else
	{
		arg[*i] = finish_substi(minishell->lexer->tokens[*pos]->str, \
		minishell->env);
		(*pos)++;
		(*i)++;
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
		find_arg(minishell, &pos, &i, arg);
	}
	arg[i] = NULL;
	i = 0;
	while (pos < minishell->lexer->size
		&& minishell->lexer->tokens[pos]->type == TOKEN_WORD)
		i++;
	minishell->lexer->pos += i - 1;
	return (arg);
}
