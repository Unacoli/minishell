/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:40:42 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/14 14:19:55 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_new_elem(t_env *envi, char *msg)
{
	while (envi->next)
		envi = envi->next;
	envi->next = ft_calloc(1, sizeof(t_env));
	if (!envi->next)
		return (error_message(NULL, 1));
	envi = envi->next;
	envi->line = create_line(msg, 0, envi->line);
	envi = NULL;
	return (0);
}

static void	reset_pwd(t_env **env, char *path)
{
	t_env	*envi;
	char	*temp;

	envi = *env;
	if (*env == NULL)
	{
		temp = ft_strjoin("PWD=", path);
		*env = new_elem(temp);
		free(temp);
	}
	else
	{
		temp = search_env(**env, "PWD");
		if (temp == NULL)
			create_new_elem(envi, "PWD=");
	}
}

static int	create_new_pwd(t_env *envi, char *msg, char *str)
{
	free(envi->line);
	envi->line = ft_strjoin(msg, str);
	if (!(envi->line))
		return (1);
	return (0);
}

static int	ft_change_pwd(t_env **env)
{
	t_env	*envi;
	char	*path;

	envi = *env;
	path = get_pwd();
	if (path == NULL)
		return (1);
	reset_pwd(env, path);
	while (envi != NULL)
	{
		if (!ft_strncmp(envi->line, "PWD=", 4))
			create_new_pwd(envi, "PWD=", path);
		envi = envi->next;
	}
	free(path);
	return (0);
}

int	cd(t_env **env, char **args)
{
	char	*path;

	if (args[1] == NULL)
		path = search_env(**env, "HOME");
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
		if (ft_change_pwd(env))
			return (error_message(NULL, 1));
		else
			return (0);
	}
}
