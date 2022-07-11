/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:47:40 by nargouse          #+#    #+#             */
/*   Updated: 2022/07/11 01:33:57 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newstr(size_t n)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * n);
	if (!result)
		return (NULL);
	ft_bzero(result, n);
	return (result);
}
