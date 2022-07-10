/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_substi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:50:01 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/10 04:09:04 by nargouse         ###   ########.fr       */
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

static t_regex	cpystr(char *str, char *input, int i)
{
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return ((t_regex){NULL, 0, TOKEN_NOT_VALID});
	ft_strlcpy(str, input, i + 2);
	str = delete_quote(str);
	return ((t_regex){str, i + 1, TOKEN_WORD});
}

t_regex	handle_quote(char *input, char c)
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
	printf("Quote is not closed !\n");
	return ((t_regex){NULL, 1, TOKEN_NOT_VALID});
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
