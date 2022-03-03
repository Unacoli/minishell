/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:51:40 by nargouse          #+#    #+#             */
/*   Updated: 2021/09/23 23:33:54 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_intmin(int *p_char)
{
	if (write(1, "-2147483648", 11) == -1)
		return (-1);
	*p_char += 11;
	return (0);
}

static int	ft_unsigned_nbr(unsigned int u, int *p_char)
{
	char	c;

	if (u > 9)
	{
		if (ft_unsigned_nbr(u / 10, p_char))
			return (-1);
		return (ft_unsigned_nbr(u % 10, p_char));
	}
	c = u + '0';
	*p_char += 1;
	if (write(1, &c, 1) == -1)
		return (-1);
	return (0);
}

static int	ft_signed_nbr(int i, int *p_char)
{
	char	c;

	if (i == INT_MIN)
		return (ft_intmin(p_char));
	if (i < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		*p_char += 1;
		i *= -1;
	}
	if (i > 9)
	{
		if (ft_signed_nbr(i / 10, p_char))
			return (-1);
		return (ft_signed_nbr(i % 10, p_char));
	}
	c = i + '0';
	*p_char += 1;
	if (write(1, &c, 1) == -1)
		return (-1);
	return (0);
}

int	ft_flag_u(va_list va, int *p_char)
{
	unsigned int	u;

	u = va_arg(va, unsigned int);
	if (ft_unsigned_nbr(u, p_char) == -1)
		return (-1);
	return (0);
}

int	ft_flag_di(va_list va, int *p_char)
{
	int	i;

	i = va_arg(va, int);
	if (ft_signed_nbr(i, p_char) == -1)
		return (-1);
	return (0);
}
