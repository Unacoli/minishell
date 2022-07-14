/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:38:59 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/14 14:56:35 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	handle_word(char *input, t_token *rlist, t_env *env)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	i = delimite_word(input, i, rlist);
	str = create_str(input, i);
	if (str == NULL)
		return ((t_token){NULL, 0, TOKEN_NOT_VALID});
	temp = search_substi(env, str);
	if (temp != str)
		free(str);
	return ((t_token){temp, i, TOKEN_WORD});
}

int	is_operator(char *input, t_token *rlist)
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

static t_token	handle_operator(int i, t_token *rlist)
{
	char	*str;

	str = create_str((char *) rlist[i].str, rlist[i].len);
	return ((t_token){str, rlist[i].len, rlist[i].type});
}

/*	Affilie les tokens operator, puis les quotes, puis les substitutions
	et si ce n'est aucun des trois, considere que c'est un mot 
	En cas d'erreur cette fonction et toute les dependantes renvoie 
	TOKEN_NOT_VALID */

t_token	get_token(char *input, t_env *env, t_token *rlist)
{
	int		i;

	i = 0;
	while (i < (MAX_TOKENS - 1))
	{
		if (!ft_strncmp(rlist[i].str, input, rlist[i].len))
			return (handle_operator(i, rlist));
		i++;
	}
	if (*input == DOUBLE_QUOTE || *input == SINGLE_QUOTE)
		return (handle_quote(input, *input));
	if (*input == '$')
		return (handle_substitution(input, env, rlist));
	else
		return (handle_word(input, rlist, env));
}
