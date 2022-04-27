/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autres.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:57:27 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/04/27 17:58:53 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child(char *path, char **argv, char**env)
{
	if (execve(path, argv, env) == -1)
		printf("minishell: command not found\n");
	freetab(env);
	freetab(argv);
	free(path);
	exit(6);
}
