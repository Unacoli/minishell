/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function_of_nfelsemb.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:24:07 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/06/02 10:17:04 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	coredump(int sig)
{
	ft_putstr_fd("Quit (core dumped)\n", 2);
	(void) sig;
}

void	childctrlc(int sig)
{
	ft_putstr_fd("\n", 2);
	(void) sig;
}

void	freetr(char	**pa, char *name, int i)
{
	while (pa[i])
	{
		free(pa[i]);
		i++;
	}
	free(name);
	free(pa);
}

char	*getna(char *cmd)
{
	char	*name;

	name = ft_strdup("/");
	while (*cmd != ' ' && *cmd)
	{
		name = ft_strjoinchar(name, *cmd);
		cmd++;
	}
	return (name);
}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
