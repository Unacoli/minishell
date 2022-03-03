/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:28:49 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 04:36:17 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char const *s1, char const *s2, size_t n)
{
	char	*result;
	int		i;
	int		j;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] && j < (int)n)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	free((char *)s1);
	return (result);
}
