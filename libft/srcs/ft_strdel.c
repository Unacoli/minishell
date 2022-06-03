/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:08:35 by nargouse          #+#    #+#             */
/*   Updated: 2022/06/03 12:32:14 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Attention segfault TwT sans doute a cause de la ligne 23 et 24 */

char	*ft_strdel(char *str, size_t n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	ptr[0] = '\0';
	if (n > ft_strlen(str))
		str = ptr;
	else
	{
		while (str[i + n] != '\0')
		{
			ptr[i] = str[i + n];
			i++;
		}
		ptr[i] = '\0';
		str = ptr;
	}
	return (str);
}
