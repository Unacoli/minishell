/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:38:59 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/11 19:44:00 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const t_regex	rl66ist[] = {
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

int	is_operator(char *input)
{
	int	i;

	i = 0;
	while (i < (MAX_TOKENS - 1))
	{
		if (!ft_strncmp(rlist[i].str, input, rlist[i].len))
			return (1);
		i++;
	}
	return (0);
}

static t_regex	handle_operator(int i)
{
	char	*str;

	str = create_str((char *) rlist[i].str, rlist[i].len);
	return ((t_regex){str, rlist[i].len, rlist[i].type});
}

/*	Affilie les tokens operator, puis les quotes, puis les substitutions
	et si ce n'est aucun des trois, considere que c'est un mot 
	En cas d'erreur cette fonction et toute les dependantes renvoie 
	TOKEN_NOT_VALID */

t_regex	get_token(char *input, t_env *env)
{
	int		i;
	t_regex	rlist[11];

	rlist = (t_regex [11]) {{">>", 2, TOKEN_DGREAT}, {"<<", 2, TOKEN_DLESS},{"\n", 1, TOKEN_NEWLINE}, {"|", 1, TOKEN_PIPE}, {">", 1, TOKEN_GREAT}, {"<", 1, TOKEN_LESS}, {" ", 1, TOKEN_PASS}, {"\v", 1, TOKEN_PASS}, {"\t", 1, TOKEN_PASS}, {"\r", 1, TOKEN_PASS}, {"\f", 1, TOKEN_PASS}, {NULL, 0, TOKEN_NOT_VALID}};
	i = 0;
	while (i < (MAX_TOKENS - 1))
	{
		if (!ft_strncmp(rlist[i].str, input, rlist[i].len))
			return (handle_operator(i));
		i++;
	}
	if (*input == DOUBLE_QUOTE || *input == SINGLE_QUOTE)
		return (handle_quote(input, *input));
	if (*input == '$')
		return (handle_substitution(input, env));
	else
		return (handle_word(input));
}
