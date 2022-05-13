/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:39:27 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/13 16:54:19 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_env_elem(t_env *env)
{
	if (env)
	{
		if (env->line)
			free(env->line);
		free(env);
	}
}

void	unset(t_env *env, char **args)
{
	t_env	*prev;
	t_env	*first;
	int		i;

	i = 0;
	prev = env;
	first = env;
	while (args[i])
	{
		env = first;
		while (env->next
			&& ft_strncmp(env->line, args[i], ft_strlen(args[i])) != 0)
		{
			prev = env;
			env = env->next;
		}
		if (ft_strncmp(env->line, args[i], ft_strlen(args[i++])) == 0)
		{
			if (env == first)
				first = env->next;
			prev->next = env->next;
			free_env_elem(env);
		}
	}
	return (0);
}
