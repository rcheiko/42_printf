/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:43:10 by rcheiko           #+#    #+#             */
/*   Updated: 2021/03/10 15:43:52 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	aff_cs(t_flags *d, const char *format, va_list arg, int i)
{
	char	*str;
	char	c;

	if (format[i] == 'c')
	{
		c = va_arg(arg, int);
		d->c = c;
		d->type = 'c';
	}
	else if (format[i] == 's')
	{
		str = va_arg(arg, char *);
		if (str == NULL)
		{
			d->str = ft_strdup("(null)");
		}
		else
			d->str = ft_strdup(str);
		d->type = 's';
	}
	else if (format[i] == '%')
	{
		d->c = '%';
		d->type = '%';
	}
}

void	aff_x(t_flags *d, const char *format, va_list arg, int i)
{
	char			*str;
	unsigned int	a;

	if (format[i] == 'x')
	{
		a = va_arg(arg, unsigned int);
		if (a == 0 && d->precision == 0)
			str = ft_strdup("");
		else
			str = print_unsigned_base(a, "0123456789abcdef");
		d->str = str;
		d->type = 'x';
	}
	else if (format[i] == 'X')
	{
		a = va_arg(arg, unsigned int);
		if (a == 0 && d->precision == 0)
			str = ft_strdup("");
		else
			str = print_unsigned_base(a, "0123456789ABCDEF");
		d->str = str;
		d->type = 'X';
	}
}

void	aff_diu(t_flags *d, const char *format, va_list arg, int i)
{
	char	*str;
	int		a;

	if (format[i] == 'd' || format[i] == 'i')
	{
		a = va_arg(arg, int);
		if (a == 0 && d->precision == 0)
			str = ft_strdup("");
		else
			str = ft_itoa(a);
		d->str = str;
		d->type = 'd';
	}
	else if (format[i] == 'u')
	{
		a = va_arg(arg, unsigned int);
		if (a == 0 && d->precision == 0)
			str = ft_strdup("");
		else
			str = ft_itoa_minus(a);
		d->str = str;
		d->type = 'u';
	}
}

void	aff_p(t_flags *d, const char *format, va_list arg, int i)
{
	char	*str;

	if (format[i] == 'p')
	{
		str = print_unsigned_base(va_arg(arg, unsigned long),
				"0123456789abcdef");
		d->str = str;
		d->type = 'p';
	}
}
