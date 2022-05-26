/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:28:54 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/26 15:31:40 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Si buff n'est pas assez grand, on augmente size*/

char	*get_pwd(void)
{
	char	*buf;
	int		size;

	size = 50;
	buf = ft_calloc(size, sizeof(char));
	while (getcwd(buf, size) == NULL)
	{
		free(buf);
		size += 50;
		buf = ft_calloc(size, sizeof(char));
	}
	return (buf);
}

void	pwd(void)
{
	char	*path;

	path = get_pwd();
	printf("%s\n", path);
	free(path);
}
