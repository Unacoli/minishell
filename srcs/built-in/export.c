/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:29:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/10 14:22:16 by ldubuche         ###   ########.fr       */
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
	if (!key)
		return (error_message(NULL, 1));
	while (env->next && ft_strncmp(env->line, key, ft_strlen(key)) != 0)
		env = env->next;
	if (!env->next && ft_strncmp(env->line, key, ft_strlen(env->line)) != 0)
	{
		env->next = ft_calloc(1, sizeof(t_env));
		if (!env->next)
			return (error_message(NULL, 1));
		env = env->next;
	}
	env->line = arg;
	env = temp;
	return (0);
}

static void	affiche(char *lower, int fd)
{
	write(fd, "declare -x ", 11);
	while (*lower && *lower != '=')
	{
		write(fd, lower, 1);
		lower++;
	}
	if (*lower)
		lower++;
	write(fd, "=\"", 2);
	while (*lower)
	{
		write(fd, lower, 1);
		lower++;
	}
	write(fd, "\"\n", 2);
}

static void	affiche_env_alpha(t_env *env, int fd)
{
	t_env	*temp;
	char	*lower;

	temp = env;
	lower = first_lower(*env);
	affiche(lower, fd);
	while (lower != NULL)
	{
		env = temp;
		lower = next_lower(*env, lower);
		if (lower != NULL)
			affiche(lower, fd);
	}
}

int	exporti(t_env *env, char **args, int fd)
{
	int	i;
	int	retour;

	i = 1;
	retour = 0;
	if (args[1] == NULL)
		affiche_env_alpha(env, fd);
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
