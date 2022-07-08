/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:38:59 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/08 03:16:22 by nargouse         ###   ########.fr       */
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

static t_regex	handle_word(char *input)
{
	int		i;
	char	*str;

	i = 0;
	i = delimite_word(input, i);
	str = create_str(input, i);
	if (str == NULL)
		return ((t_regex){NULL, 0, TOKEN_NOT_VALID});
	return ((t_regex){str, i, TOKEN_WORD});
}

static t_regex	handle_operator(int i)
{
	char *str;

	str = create_str((char *) g_rlist[i].str, g_rlist[i].len);
	return ((t_regex){str, g_rlist[i].len, g_rlist[i].type});
}

/*	Affilie les tokens operator, puis les quotes, puis les substitutions
	et si ce n'est aucun des trois, considere que c'est un mot 
	En cas d'erreur cette fonction et toute les dependantes renvoie 
	TOKEN_NOT_VALID */

t_regex	get_token(char *input)
{
	int	i;

	i = 0;
	while (i < (MAX_TOKENS - 1))
	{
		if (!ft_strncmp(g_rlist[i].str, input, g_rlist[i].len))
			return (handle_operator(i));
		i++;
	}
	if (*input == DOUBLE_QUOTE || *input == SINGLE_QUOTE)
		return (handle_quote(input, *input));
	if (*input == '$')
		return (handle_substitution(input));
	else
		return (handle_word(input));
}
