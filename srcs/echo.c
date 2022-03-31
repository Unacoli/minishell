/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:22:10 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/31 17:27:16 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getname(char *cmd, int i)
{
	char	*name;

	name = ft_strdup("");
	while (cmd[i] != ' ' && cmd[i])
	{
		name = ft_strjoinchar(name, cmd[i]);
		i++;
	}
	return (name);
}

char	*echo(char	*cmd, t_env *enviro, int tiretn)
{
	char	*d;
	int		i;

	i = 0;
	d = ft_strdup("");
	while (cmd[i])
	{
		if (cmd[i] != '$')
			d = ft_strjoinchar(d, cmd[i]);
		else
		{
			i++;
			d = ft_strjoin(d, getvale(getname(cmd, i), enviro));
			while (cmd[i] != ' ' && cmd[i])
				i++;
		}
		i++;
	}
	if (tiretn)
		return (d);
	return (ft_strjoinchar(d, '\n'));
}