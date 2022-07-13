/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 03:08:26 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 19:29:37 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

static char	**find_tokens(char **args, int nbr)
{
	int		i;
	int		j;
	char	**result;
	char	*temp;

	i = 1;
	j = 0;
	result = ft_calloc(sizeof(char *), nbr + 1);
	while (args[i] != NULL && j < nbr)
	{
		if (is_equal(args[i]))
			temp = args[i++];
		while (args[i] && !is_equal(args[i]))
		{
			if (is_equal(temp) && result[0])
				temp = ft_strjoin(temp, args[i]);
			else
				temp = ft_strjoin_free1(temp, args[i]);
			i++;
		}
		result[j] = ft_strdup(temp);
		j++;
	}
	result[j] = NULL;
	free(temp);
	return (result);
}

char	**join_token(char **args)
{
	int		i;
	int		nbr_res;
	char	**result;

	i = 0;
	nbr_res = 0;
	result = NULL;
	while (args[i])
	{
		if (is_equal(args[i]))
			nbr_res++;
		i++;
	}
	if (i > 1)
		result = find_tokens(args, nbr_res);
	return (result);
}
