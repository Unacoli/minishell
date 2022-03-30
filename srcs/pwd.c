/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:27:51 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/30 15:05:56 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pwd(void)
{
	char	*buf;

	buf = ft_calloc(50, sizeof(char));
	getcwd(buf, 50);
	buf = ft_strjoinchar(buf, '\n');
	return (buf);
}

char	*envi(char **env)
{
	int		i;
	char	*d;

	i = 0;
	d = ft_strdup("");
	while (env[i])
	{
		d = ft_strjoin(d, env[i]);
		d = ft_strjoinchar(d, '\n');
		i++;
	}
	return (d);
}
