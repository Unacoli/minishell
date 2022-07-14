/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:45:04 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 03:08:43 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_error(t_lexer *lexer)
{
	size_t	i;

	i = 0;
	while (i < lexer->size)
	{
		if (lexer->tokens[i]->str == NULL)
		{
			g_status = 1;
			return (1);
		}
		if (lexer->tokens[i]->type == TOKEN_NOT_VALID)
		{
			g_status = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\v' || c == '\t' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

char	*create_str(char *input, int i)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, input, (size_t)(i + 1));
	return (str);
}

int	delimite_word(char *input, int i, t_token *rlist)
{
	while (input[i] && !is_separator(&(input[i]), rlist) && input[i] != '\n')
		i++;
	return (i);
}

int	delimite_word_substi(char *input, int i, t_token *rlist)
{
	if (input[i + 1] == '?')
		return (i + 2);
	while (input[i] && !is_separator(&(input[i]), rlist) && input[i] != '\n')
		i++;
	return (i);
}
