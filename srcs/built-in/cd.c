/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:40:42 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/07 04:12:59 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_change_old_pwd(t_env *env, char *path)
{
	int		diff;
	char	*temp;

	free(env->line);
	diff = ft_strrchr(path, '/') - path;
	temp = (char *) malloc(sizeof(char) * (diff + 1));
	if (!temp)
		return (1);
	ft_strlcpy(temp, path, diff + 1);
	env->line = ft_strjoin_free("OLD_PWD=", temp + 4);
	if (!(env->line))
		return (1);
	return (0);
}

static int	ft_change_pwd(t_env env)
{
	t_env	*envi;
	char	*path;

	envi = &env;
	path = get_pwd();
	if (path == NULL)
		return (1);
	while (envi->next != NULL)
	{
		if (!ft_strncmp(envi->line, "PWD=", 4))
		{
			free(envi->line);
			envi->line = ft_strjoin_free("PWD=", path);
			if (!(envi->line))
				return (1);
		}
		else if (!ft_strncmp(envi->line, "OLD_PWD=", 4))
			if (ft_change_old_pwd(envi, path))
				return (1);
		envi = envi->next;
	}
	return (0);
}

int	cd(t_env *env, char **args)
{
	char	*path;

	if (args == NULL || args[0] == NULL)
		path = search_env(*env, "HOME");
	else
	{
		path = args[1];
		if (args[2] != NULL)
			return (error_message("cd: too many arguments", 1));
	}
	if (path == NULL)
		return (error_message("cd: Path to HOME not found", 1));
	if (chdir(path))
		return (error_message(NULL, 1));
	else
	{
		if (ft_change_pwd(*env))
			return (error_message(NULL, 1));
		else
			return (0);
	}
}
