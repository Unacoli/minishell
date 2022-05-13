/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:51:59 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/13 16:27:17 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_key(char *arg)
{
	char	*key;
	int		i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	key = (char *) malloc(sizeof(char) * (i + 1));
	if (!key)
		return (NULL);
	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		key[i] = arg[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*first_lower(t_env env)
{
	char	*lower;
	t_env	*temp;

	temp = &env;
	lower = temp->line;
	temp = temp->next;
	while (temp)
	{
		if (ft_strncmp(lower, temp->line, ft_strlen(lower) + 1) < 0)
			lower = temp->line;
		temp = temp->next;
	}
	return (lower);
}

char	*next_lower(t_env env, char *previous)
{
	char	*lower;
	t_env	*temp;

	temp = &env;
	lower = previous;
	temp = temp->next;
	while (temp)
	{
		if (ft_strncmp(lower, temp->line, ft_strlen(lower) + 1) < 0
			&& ft_strncmp(previous, temp->line, ft_strlen(previous) + 1) > 0)
			lower = temp->line;
		temp = temp->next;
	}
	if (lower == previous)
		return (NULL);
	return (lower);
}
