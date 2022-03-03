/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:10:33 by nargouse          #+#    #+#             */
/*   Updated: 2021/09/24 18:10:09 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_long_abs(long i, int *p_char)
{
	if (i == LONG_MIN)
	{
		if (write(1, "8000000000000000", 16) == -1)
			return (-1);
	}
	else if (i == LONG_MAX)
	{
		if (write(1, "7fffffffffffffff", 16) == -1)
			return (-1);
	}
	else if ((unsigned long)i == ULONG_MAX)
	{
		if (write(1, "ffffffffffffffff", 16) == -1)
			return (-1);
	}
	(*p_char) += 16;
	return (0);
}

static int	ft_putchar(char c, int *p_char)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*p_char)++;
	return (0);
}

static int	ft_p(long i, char *hexa, int *p_char)
{
	if (i == LONG_MIN || i == LONG_MAX || (unsigned long)i == ULONG_MAX)
	{
		if (ft_long_abs(i, p_char) == -1)
			return (-1);
		return (0);
	}
	if (i < 0)
		i *= -1;
	if (i > 15)
	{
		ft_p(i / 16, hexa, p_char);
		ft_p(i % 16, hexa, p_char);
	}
	if (i < 16)
	{
		if (ft_putchar(hexa[i % 16], p_char) == -1)
			return (-1);
	}
	return (0);
}

int	ft_flag_p(va_list va, int *p_char)
{
	long	str;
	char	*hexa;

	hexa = "0123456789abcdef";
	str = va_arg(va, long);
	write(1, "0x", 2);
	(*p_char) += 2;
	if (ft_p(str, hexa, p_char) == -1)
		return (-1);
	return (0);
}
