/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:28:54 by ldubuche          #+#    #+#             */
/*   Updated: 2022/07/07 01:09:15 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Si buff n'est pas assez grand, on augmente size*/

char	*get_pwd(void)
{
	char	*buf;
	int		size;

	size = 50;
	buf = NULL;
	buf = ft_calloc(size, sizeof(char));
	if (!buf)
		return (NULL);
	while (getcwd(buf, size) == NULL)
	{
		free(buf);
		size += 50;
		buf = ft_calloc(size, sizeof(char));
		if (!buf)
			return (NULL);
	}
	return (buf);
}

int	pwd(void)
{
	char	*path;

	path = get_pwd();
	if (!path)
		return (1);
	printf("%s\n", path);
	free(path);
	return (0);
}
