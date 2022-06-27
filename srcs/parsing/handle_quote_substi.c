/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_substi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:50:01 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/27 12:05:52 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Parcours tout l'input jusqu'a la quote correspondante 
	Et le stocke dans un seul token */

t_regex	handle_quote(char *input, char c)
{
	int		i;
	char	*str;

	i = 1;
	while (input[i] != c)
	{
		if (!input[i] && input[i] != c)
		{
			printf("Quote is not closed !");
			return ((t_regex){NULL, 0, TOKEN_NOT_VALID});
		}
		i++;
	}
	str = (char *) malloc(sizeof(char) * (i + 3));
	if (str == NULL)
		return ((t_regex){NULL, 0, TOKEN_NOT_VALID});
	ft_strlcpy(str, input, i + 2);
	return ((t_regex){str, i + 1, TOKEN_WORD});
}

t_regex	handle_substitution(char *input)
{
	int		i;
	char	*str;

	i = delimite_word(input, 1);
	str = create_str(input, i);
	if (str == NULL)
		return ((t_regex){NULL, 0, TOKEN_NOT_VALID});
	return ((t_regex){str, i, TOKEN_WORD});
}
