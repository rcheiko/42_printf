/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:57:38 by rcheiko           #+#    #+#             */
/*   Updated: 2021/03/10 15:39:52 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_flags *d)
{
	d->zero = 0;
	d->minus = 0;
	d->point = 0;
	d->largeur = 0;
	d->precision = -1;
	d->type = 0;
	d->c = 0;
	d->str = NULL;
	d->result = NULL;
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		to;
	va_list	arg;
	t_flags	d;

	i = 0;
	to = 0;
	va_start(arg, format);
	while (format[i])
	{
		init_struct(&d);
		if (format[i] != '%' && format[i])
			to = ft_putchar(format[i++], to);
		else
		{
			i = traitement(format, &d, arg, i);
			to += aff_result(&d, to);
			free(d.str);
		}
	}
	va_end(arg);
	return (to);
}
