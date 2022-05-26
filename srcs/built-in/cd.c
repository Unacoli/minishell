/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:40:42 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/26 15:51:50 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_change_pwd(t_env env)
{
	t_env 	*envi;
	char	*path;
	char	*temp;
	int		diff;

	envi = &env;
	path = get_pwd();
	while (envi->next != NULL)
	{
		if (!ft_strncmp(envi->line, "PWD=", 4))
		{
			free(envi->line);
			envi->line = ft_strjoin_free("PWD=", path);
		}
		else if (!ft_strncmp(envi->line, "OLD_PWD=", 4))
		{
			free(envi->line);
			diff = ft_strrchr(pwd, '/') - pwd;
			temp = (char *) malloc(sizeof(char) * (diff + 1));
			ft_strlcpy(temp, pwd, diff + 1);
			envi->line = ft_strjoin_free("OLD_PWD=", temp+4);
		}
		envi = envi->next;
	}
	return (0);
}

int	cd(t_env env, char **args)
{
	char	*path;

	if (args == NULL || args[0] == NULL)
		path = search_env(env, "HOME");
	else
	{
		path = args[0];
		if (args[1] != NULL)
		{
			printf("cd : too many arguments\n");
			return (1);
		}
	}
	if (path == NULL)
	{
		printf("Path to HOME not found\n");
		return (1);
	}
	if (chdir(path))
	{
		printf("'%s' : No such file or directory\n", path);
		return (1);
	}
	else
		return (ft_change_pwd(env));
}
