/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:18:50 by pmontiel          #+#    #+#             */
/*   Updated: 2021/03/10 15:15:05 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		traitement_s(t_flags *d)
{
	int i;

	i = 0;
	if (d->point)
	{
		if (d->largeur < ft_strlen(d->str) && d->precision != 0 &&
			(d->precision >= ft_strlen(d->str) || d->precision < 0))
			i = affichage_int_global(d);
		else if (d->minus)
			i = affichage_s_1_minus(d);
		else if (!d->minus)
			i = affichage_s_1(d);
	}
	else if (!d->point)
	{
		if (d->largeur < ft_strlen(d->str))
			i = affichage_int_global(d);
		else if (d->minus && d->largeur)
			i = affichage_s_2_minus(d);
		else if (!d->minus && d->largeur)
			i = affichage_s_2(d);
	}
	return (i);
}

int		affichage_s_1_minus(t_flags *d)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = -1;
	if (d->precision > 0)
	{
		if (d->precision >= ft_strlen(d->str) && d->largeur > ft_strlen(d->str))
			j = d->largeur - ft_strlen(d->str);
		if (d->precision < ft_strlen(d->str) && d->largeur > d->precision)
			j = d->largeur - d->precision;
	}
	if (d->precision == 0)
		j = d->largeur;
	if (d->precision < 0)
		i = ft_putstr_count(d->str, i);
	if (d->precision < 0)
		j = d->largeur - ft_strlen(d->str);
	if (d->precision > 0)
		i += ft_putnstr(d->str, d->precision);
	while (++k < j)
		i = ft_putchar(' ', i);
	return (i);
}

int		affichage_s_1(t_flags *d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (d->precision > 0)
	{
		if (d->precision >= ft_strlen(d->str) && d->largeur > ft_strlen(d->str))
			j = d->largeur - ft_strlen(d->str);
		if (d->precision < ft_strlen(d->str) && d->largeur > d->precision)
			j = d->largeur - d->precision;
	}
	if (d->precision == 0)
		j = d->largeur;
	if (d->precision < 0)
		j = d->largeur - ft_strlen(d->str);
	while (i < j)
		i = ft_putchar(' ', i);
	if (d->precision < 0)
		i = ft_putstr_count(d->str, i);
	if (d->precision != 0)
		i += ft_putnstr(d->str, d->precision);
	return (i);
}

int		affichage_s_2_minus(t_flags *d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	i = ft_putstr_count(d->str, i);
	while (j < d->largeur - ft_strlen(d->str))
	{
		i = ft_putchar(' ', i);
		j++;
	}
	return (i);
}

int		affichage_s_2(t_flags *d)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < d->largeur - ft_strlen(d->str))
	{
		i = ft_putchar(' ', i);
		j++;
	}
	i = ft_putstr_count(d->str, i);
	return (i);
}
