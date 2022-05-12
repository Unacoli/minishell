/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:28:54 by ldubuche          #+#    #+#             */
/*   Updated: 2022/05/12 16:08:34 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Si buff n'est pas assez grand, on augmente size*/

char	*pwd(void)
{
	char	*buf;
	int		size;

	size = 50;
	buf = ft_calloc(size, sizeof(char));
	while (getcwd(buf, size) == NULL)
	{
		size += 50;
		buf = ft_calloc(size, sizeof(char));
	}
	buf = ft_strjoinchar(buf, '\n');
	return (buf);
}
