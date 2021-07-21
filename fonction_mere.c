/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_mere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:41:11 by rcheiko           #+#    #+#             */
/*   Updated: 2021/05/19 12:19:13 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		traitement(const char *format, t_flags *d, va_list arg, int i)
{
	if (format[i] == '%')
		i++;
	i = fill_struc_min_zero(d, format, i);
	i = fill_struc_larg(d, format, arg, i);
	fill_struc_dot(d, format, i);
	i = fill_struc_preci(d, format, arg, i);
	aff_cs(d, format, arg, i);
	aff_x(d, format, arg, i);
	aff_diu(d, format, arg, i);
	aff_p(d, format, arg, i);
	i++;
	return (i);
}

int		aff_result(t_flags *d, int to)
{
	if (d->type == 'd' || d->type == 'i' || d->type == 'u' ||
			d->type == 'x' || d->type == 'X')
		to = traitement_int(d);
	else if (d->type == 'p')
		to = traitement_p(d);
	else if (d->type == 'c')
		to = traitement_c(d);
	else if (d->type == '%')
	{
		to = traitement_c(d);
		to += traitement_pourc(d);
	}
	else if (d->type == 's')
		to = traitement_s(d);
	return (to);
}
