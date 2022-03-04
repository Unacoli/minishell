/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:12:45 by nargouse          #+#    #+#             */
/*   Updated: 2021/09/23 18:37:39 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_putchar(char c, int *p_char)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*p_char)++;
	return (0);
}

static int	ft_x(unsigned int n, int *p_char)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n > 15)
	{
		ft_x(n / 16, p_char);
		ft_x(n % 16, p_char);
	}
	if (n < 16)
	{
		if (ft_putchar(hexa[n % 16], p_char) == -1)
			return (-1);
	}
	return (0);
}

static int	ft_big_x(unsigned int n, int *p_char)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_big_x(n / 16, p_char);
		ft_big_x(n % 16, p_char);
	}
	if (n < 16)
	{
		if (ft_putchar(hexa[n % 16], p_char) == -1)
			return (-1);
	}
	return (0);
}

int	ft_flag_x(va_list va, int *p_char, char format)
{
	unsigned int	n;

	n = va_arg(va, unsigned int);
	if (format == 'x')
	{
		if (ft_x(n, p_char) == -1)
			return (-1);
	}
	else if (format == 'X')
	{
		if (ft_big_x(n, p_char) == -1)
			return (-1);
	}
	return (0);
}
