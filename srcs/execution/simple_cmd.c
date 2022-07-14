/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:35:00 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/14 01:21:10 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*finish_substi(char *to_treat)
{
	char	*str;

	str = ft_strdup(to_treat);
	return (str);
}

void	find_arg(t_ctrl *minishell, size_t *pos, int *i, char **arg)
{
	if (minishell->lexer->tokens[*pos]->type >= TOKEN_LESS \
		&& minishell->lexer->tokens[*pos]->type <= TOKEN_DLESS)
		*pos += 2;
	else
	{
		arg[*i] = finish_substi(minishell->lexer->tokens[*pos]->str);
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
