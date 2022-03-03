/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:39:46 by nargouse          #+#    #+#             */
/*   Updated: 2021/09/23 23:16:36 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_conversion(va_list va, const char *format, int *p_char, int *i)
{
	(*i)++;
	if (format[*i] == 'c')
		return (ft_flag_c(va, p_char));
	else if (format[*i] == 's')
		return (ft_flag_s(va, p_char));
	else if (format[*i] == 'p')
		return (ft_flag_p(va, p_char));
	else if (format[*i] == 'd' || format[*i] == 'i')
		return (ft_flag_di(va, p_char));
	else if (format[*i] == 'u')
		return (ft_flag_u(va, p_char));
	else if (format[*i] == 'x' || format[*i] == 'X')
		return (ft_flag_x(va, p_char, format[*i]));
	else if (format[*i] == '%')
		return (ft_flag_pourcent(p_char));
	else
		(*i)--;
	return (0);
}

static int	ft_while(va_list va, const char *format, int *p_char)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_conversion(va, format, p_char, &i) == -1)
				return (-1);
		}	
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			*p_char += 1;
		}
		i++;
	}
	va_end(va);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	int		p_char;

	va_start(va, format);
	p_char = 0;
	if (ft_while(va, format, &p_char))
		return (-1);
	return (p_char);
}
