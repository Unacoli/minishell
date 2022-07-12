/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote_substi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:50:01 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/12 19:53:51 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Parcours tout l'input jusqu'a la quote correspondante 
	Et le stocke dans un seul token */

char	*delete_quote(char *str, int i)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (ft_strlen(str) - 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, str + 1, ft_strlen(str) - 1);
	if (i != 1)
		free(str);
	return (result);
}

static t_token	cpystr(char *str, char *input, int i)
{
	str = (char *)malloc(sizeof(char) * (i + 2));
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
	g_status = 1;
	str = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(str, input, i);
	return ((t_token){str, i, TOKEN_NOT_VALID});
}

t_token	handle_substitution(char *input, t_env *env, t_token *rlist)
{
	int		i;
	char	*str;
	char	*temp;

	i = delimite_word_substi(input, 0, rlist);
	temp = create_str(input, i);
	if (temp == NULL)
		return ((t_token){NULL, 0, TOKEN_NOT_VALID});
	str = search_substi(env, temp);
	free(temp);
	return ((t_token){str, i, TOKEN_WORD});
}
