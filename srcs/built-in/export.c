/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:29:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/06/02 10:05:24 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_identifier_valid(char *name)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(name[i]) || name[i] == '_'))
		return (0);
	i++;
	while (name[i] && name[i] != '=')
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static int	export_value(t_env *env, char *arg)
{
	char	*key;
	t_env	*temp;

	temp = env;
	if (is_identifier_valid(arg) == 0)
		return (non_valid_identifier(arg, "export"));
	key = find_key(arg);
	while (env->next && ft_strncmp(env->line, key, ft_strlen(key)) != 0)
		env = env->next;
	if (!env->next && ft_strncmp(env->line, key, ft_strlen(env->line)) != 0)
	{
		env->next = ft_calloc(1, sizeof(t_env));
		env = env->next;
	}
	env->line = arg;
	env = temp;
	return (0);
}

static void	affiche(char *lower)
{
	write(1, "declare -x ", 11);
	while (*lower && *lower != '=')
	{
		write(1, lower, 1);
		lower++;
	}
	if (*lower)
		lower++;
	write(1, "=\"", 2);
	while (*lower)
	{
		write(1, lower, 1);
		lower++;
	}
	write(1, "\"\n", 2);
}

static void	affiche_env_alpha(t_env *env)
{
	t_env	*temp;
	char	*lower;

	temp = env;
	lower = first_lower(*env);
	affiche(lower);
	while (lower != NULL)
	{
		env = temp;
		lower = next_lower(*env, lower);
		if (lower != NULL)
			affiche(lower);
	}
}

int	export(t_env *env, char **args)
{
	int	i;
	int	retour;

	i = 0;
	retour = 0;
	if (args == NULL)
	{
		affiche_env_alpha(env);
	}
	else
	{
		while (args[i])
		{
			if (export_value(env, args[i]))
				retour = 1;
			i++;
		}
	}
	return (retour);
}
