/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_substi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:50:01 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/12 10:58:46 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Parcours tout l'input jusqu'a la quote correspondante 
	Et le stocke dans un seul token */

char	*delete_quote(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str) - 2;
	while (i < len)
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static t_token	cpystr(char *str, char *input, int i)
{
	str = (char *) malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return ((t_token){NULL, 0, TOKEN_NOT_VALID});
	ft_strlcpy(str, input, i + 2);
	return ((t_token){str, i + 1, TOKEN_WORD});
}

t_token	handle_quote(char *input, char c)
{
	int		i;
	char	*str;
	int		j;

	i = 1;
	j = 0;
	str = NULL;
	while (input[i])
	{
		if (input[i] == c)
		{
			j++;
			if (j == 1)
				return (cpystr(str, input, i));
		}
		i++;
	}
	ft_putstr_fd("Quote is not closed !\n", STDERR_FILENO);
	return ((t_token){NULL, i, TOKEN_NOT_VALID});
}

t_token	handle_substitution(char *input, t_env *env, t_token *rlist)
{
	int		i;
	char	*str;

	i = delimite_word_substi(input, 0, rlist);
	str = create_str(input, i + 1);
	if (str == NULL)
		return ((t_token){NULL, 0, TOKEN_NOT_VALID});
	str = search_substi(env, str);
	return ((t_token){str, i, TOKEN_WORD});
}
