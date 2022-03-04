/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:21:06 by nargouse          #+#    #+#             */
/*   Updated: 2021/01/17 15:33:23 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	c;
	size_t	d;

	i = 0;
	c = 0;
	d = 0;
	while (src[c])
		c++;
	while (dst[d])
		d++;
	j = d;
	if (size > d)
	{
		while (i < size - d - 1 && src[i] != '\0')
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	else
		return (c + size);
	return (c + d);
}
