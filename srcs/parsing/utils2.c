/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:45:04 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/03 15:30:52 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_regex	g_rlist[] = {
{">>", 2, TOKEN_DGREAT},
{"<<", 2, TOKEN_DLESS},
{"\n", 1, TOKEN_NEWLINE},
{"|", 1, TOKEN_PIPE},
{">", 1, TOKEN_GREAT},
{"<", 1, TOKEN_LESS},
{" ", 1, TOKEN_PASS},
{"\v", 1, TOKEN_PASS},
{"\t", 1, TOKEN_PASS},
{"\r", 1, TOKEN_PASS},
{"\f", 1, TOKEN_PASS},
{NULL, 0, TOKEN_NOT_VALID}
};

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

int	is_operator(char *input)
{
	int	i;

	i = 0;
	while (i < (MAX_TOKENS - 1))
	{
		if (!ft_strncmp(g_rlist[i].str, input, g_rlist[i].len))
			return (1);
		i++;
	}
	return (0);
}

int	delimite_word(char *input, int i)
{
	while (input[i] && !is_space(input[i]) && !is_operator(&(input[i])))
		i++;
	return (i);
}
