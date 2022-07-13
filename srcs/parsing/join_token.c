/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 03:08:26 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 04:01:54 by ldubuche         ###   ########.fr       */
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
		temp = args[i];
		printf("find : args = %s\n", args[i + 1]);
		while (args[i + 1] && !is_equal(args[i + 1]))
		{
			temp = ft_strjoin_free1(temp, args[i + 1]);
			printf("find : temp = %s\n", temp);
			i++;
		}
		result[j] = ft_strdup(temp);
		printf("find : result[j] = %s\n", result[j]);
		j++;
	}
	result[j] = NULL;
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
	printf("i = %d\n", i);
	if (i > 1)
	{
		result = find_tokens(args, nbr_res);
		printf("join: result[0] = %s\n", result[0]);
	}
	return (result);
}
