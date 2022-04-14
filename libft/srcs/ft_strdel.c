/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:08:35 by nargouse          #+#    #+#             */
/*   Updated: 2022/04/14 16:28:35 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdel(char *str, size_t n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	ptr[0] = '\0';
	if ((int)n > ft_strlen(str))
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
