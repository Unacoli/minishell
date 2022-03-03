/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:40:24 by nargouse          #+#    #+#             */
/*   Updated: 2021/09/23 23:23:37 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_flag_c(va_list va, int *p_char);
int	ft_flag_s(va_list va, int *p_char);
int	ft_flag_p(va_list va, int *p_char);
int	ft_flag_di(va_list va, int *p_char);
int	ft_flag_u(va_list va, int *p_char);
int	ft_flag_x(va_list va, int *p_char, char format);
int	ft_flag_pourcent(int *p_char);

#endif
