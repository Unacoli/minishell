/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 03:08:26 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/13 22:13:37 by ldubuche         ###   ########.fr       */
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

static char	*choose_join(char *temp, char **args, char **result, int i)
{
	if (is_equal(temp) && result[0])
		return (ft_strjoin(temp, args[i]));
	else
		return (ft_strjoin_free1(temp, args[i]));
}

static char	**find_tokens(char **args, int nbr)
{
	int		i;
	int		j;
	char	**result;
	char	*temp;

	i = 1;
	j = 1;
	temp = NULL;
	result = ft_calloc(sizeof(char *), nbr + 2);
	result[0] = ft_strdup(args[0]);
	while (args[i] != NULL && j < nbr + 1)
	{
		if (is_equal(args[i]))
			temp = args[i++];
		while (args[i] && !is_equal(args[i]))
			temp = choose_join(temp, args, result, i++);
		result[j] = ft_strdup(temp);
		j++;
	}
	result[j] = NULL;
	if (temp && (args[i - 1]) != temp)
		free(temp);
	return (result);
}

char	**join_token(char **args)
{
	int		i;
	int		nbr_res;
	char	**result;

	i = 1;
	nbr_res = 0;
	result = NULL;
	while (args[i])
	{
		if (is_equal(args[i]))
			nbr_res++;
		i++;
	}
	if (nbr_res > 1 && nbr_res != i)
	{
		result = find_tokens(args, nbr_res);
		return (result);
	}
	return (result);
}
