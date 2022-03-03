/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:51:43 by nargouse          #+#    #+#             */
/*   Updated: 2022/01/31 22:53:17 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	n;
	int		s;
	int		i;

	n = 0;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f') && str[i] != '\0')
		i++;
	s = 1;
	if (str[i] == '-')
	{
		if (!ft_isdigit(str[i + 1]))
			return (LONG_MIN);
		s = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (LONG_MIN);
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * s);
}
