/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:35:00 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/07 18:22:53 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_suffix(size_t pos, t_ctrl *minishell)
{
	char	**arg;
	int		i;

	i = pos;
	arg = malloc(sizeof(char **));
	while (pos < minishell->lexer->size
			&& minishell->lexer->tokens[pos]->type == TOKEN_WORD)
		pos++;
	arg = (char **) malloc(sizeof(char *) * (i - pos)); //verif malloc a faire
	pos = pos - i;
	i = 0;
	while (pos < minishell->lexer->size
			&& minishell->lexer->tokens[pos]->type == TOKEN_WORD)
	{
		arg[i] = ft_strdup(minishell->lexer->tokens[pos]->str);
		pos++;
		i++;
	}
	minishell->lexer->pos += i;
	return (arg);
}