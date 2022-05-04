/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:16:13 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/04/28 15:09:00 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	chldexed(char *cmd, t_env *envi)
{
	char	**argv;
	char	**env;
	char	*path;

	argv = ft_split(cmd, ' ');
	free(cmd - 1);
	cmd = argv[0];
	env = getenvchar(envi);
	path = ft_strdup(".");
	path = ft_strjoin_free1(path, cmd);
	freeenv(envi);
	argv[0] = path;
	if (execve(path, argv, env) == -1)
		printf("minishell: %s: No such file or directory\n", "p");
	freetab(argv);
	freetab(env);
	exit(6);
}

void	exed(char *cmd, t_env *envi)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		chldexed(cmd, envi);
	else
		waitpid(pid, 0, 0);
}
