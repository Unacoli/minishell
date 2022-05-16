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

static int	is_identifier_valid(char *name)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(name[i]) || name[i] == '_'))
		return (0);
	i++;
	while (name[i])
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

int	unset(t_env *env, char **args)
{
	t_env	*prev;
	t_env	*first;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	prev = env;
	first = env;
	while (args[i])
	{
		if (is_identifier_valid(args[i]) == 0)
			ret = non_valid_identifier(args[i], "unset");
		else
		{
			env = first;
			while (env->next
				&& ft_strncmp(env->line, args[i], ft_strlen(args[i])) != 0)
			{
				prev = env;
				env = env->next;
			}
			if (ft_strncmp(env->line, args[i], ft_strlen(args[i])) == 0)
			{
				if (env == first)
					first = env->next;
				prev->next = env->next;
				free_env_elem(env);
			}
		}
		i++;
	}
	return (ret);
}
