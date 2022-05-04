/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:47:40 by nargouse          #+#    #+#             */
/*   Updated: 2022/05/04 15:23:09 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_newstr(size_t n)
{
	char	*result;

	result = (char *) malloc(sizeof(char) * n);
	if (!result)
		return (NULL);
	ft_bzero(result, n);
	return (result);
}
