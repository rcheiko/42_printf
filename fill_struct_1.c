/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:26:05 by rcheiko           #+#    #+#             */
/*   Updated: 2021/03/10 15:45:18 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fill_struc_min_zero(t_flags *d, const char *format, int i)
{
	while ((format[i] == '-' || format[i] == '0') && format[i])
	{
		if (format[i] == '-')
			d->minus = 1;
		if (format[i] == '0')
			d->zero = 1;
		i++;
	}
	if (d->minus && d->zero)
		d->zero = 0;
	return (i);
}

int		fill_struc_larg(t_flags *d, const char *format, va_list arg, int i)
{
	while (ft_isdigit(format[i]) == 1)
		d->largeur = d->largeur * 10 + (format[i++] - '0');
	if (format[i] == '*')
	{
		d->largeur = va_arg(arg, int);
		i++;
	}
	if (d->largeur < 0)
	{
		d->minus = 1;
		d->largeur *= -1;
	}
	return (i);
}

void	fill_struc_dot(t_flags *d, const char *format, int i)
{
	if (format[i] == '.')
		d->point = 1;
}

int		fill_struc_preci(t_flags *d, const char *format, va_list arg, int i)
{
	if (d->point)
	{
		i++;
		d->precision = 0;
		if (ft_isdigit(format[i]) == 1)
		{
			while (ft_isdigit(format[i]) == 1)
				d->precision = d->precision * 10 + (format[i++] - '0');
		}
		if (format[i] == '*')
		{
			d->precision = va_arg(arg, int);
			i++;
		}
	}
	return (i);
}
