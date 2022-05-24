/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:59:46 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/05/24 11:50:04 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_env(char **env)
{
	t_env	*first;
	t_env	*elem;
	int		i;

	first = (t_env *) ft_calloc(1, sizeof(t_env));
	if (first == NULL)
		return (NULL);
	elem = first;
	elem->next = NULL;
	elem->line = env[0];
	i = 1;
	while (env[i])
	{
		elem->next = (t_env *) ft_calloc(1, sizeof(t_env));
		if (elem->next == NULL)
		{
			free_env(first);
			return (NULL);
		}
		elem = elem->next;
		elem->next = NULL;
		elem->line = env[i++];
	}
	return (first);
}

char	*search_env(t_env env, char *to_search)
{
	t_env	*temp;

	temp = &env;
	while (temp)
	{
		if (ft_strnstr(temp->line, to_search, ft_strlen(to_search)))
			return (temp->line + ft_strlen(to_search) + 1);
		temp = temp->next;
	}
	return (NULL);
}

void	choose_env(char **env)
{
	t_env	*struc_env;

	if (!(*env))
		struc_env = default_env();
	else
		struc_env = init_env(env);
	signal_handler();
}
