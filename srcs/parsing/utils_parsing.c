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
	while (input[i] && !is_space(input[i]) && !is_operator(&(input[i]), rlist) \
	&& input[i] != '\n' && input[i] != '\'' && input[i] != '"')
	{
		i++;
	}
	return (i);
}

int	delimite_word_substi(char *input, int i, t_token *rlist)
{
	if (input[i + 1] == '?')
		return (i + 2);
	while (input[i] && !is_space(input[i]) && !is_operator(&(input[i]), rlist) \
	&& input[i] != '\n')
		i++;
	return (i);
}
