/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:40:42 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/13 12:52:32 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			//retour erreur "minishell: cd: too many arguments\n"
			return (1);
		}
	}
	if (chdir(path))
	{
		printf("'%s' : No such file or directory\n", path);
		//retour erreur "path, ": No such file or directory\n"
		return (1);
	}
	return (0);
}
