/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_int_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:12:28 by rcheiko           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:04 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	affichage_int_2_zero(t_flags *d)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (++j < d->largeur - ft_strlen(d->str))
		i = ft_putchar('0', i);
	i = ft_putstr_count(d->str, i);
	return (i);
}

int	affichage_int_2_minus(t_flags *d)
{
	int i;
	int j;
	int cpt;

	i = 0;
	j = 0;
	cpt = -1;
	if (d->precision > 0)
		j = aff_j_int_2(d);
	if (d->precision <= 0)
		j = d->largeur - ft_strlen(d->str);
	while (++cpt < d->precision - ft_strlen(d->str))
		i = ft_putchar('0', i);
	i += ft_strlen(d->str);
	ft_putstr_i(d->str, 0);
	cpt = -1;
	while (++cpt < j)
		i = ft_putchar(' ', i);
	return (i);
}

int	affichage_int_2(t_flags *d)
{
	int i;
	int j;
	int cpt;

	i = 0;
	j = 0;
	cpt = -1;
	if (d->precision > 0)
		j = aff_j_int_2(d);
	if (d->precision <= 0)
		j = d->largeur - ft_strlen(d->str);
	while (++cpt < j)
		i = ft_putchar(' ', i);
	cpt = -1;
	while (++cpt < d->precision - ft_strlen(d->str))
		i = ft_putchar('0', i);
	i += ft_strlen(d->str);
	ft_putstr_i(d->str, 0);
	return (i);
}

int	aff_j_int_1(t_flags *d)
{
	int j;

	j = 0;
	if (d->precision > d->largeur)
		j = 0;
	if (d->precision < d->largeur && d->precision > ft_strlen(d->str))
		j = d->largeur - d->precision - 1;
	if (d->precision < d->largeur && d->precision < ft_strlen(d->str))
		j = d->largeur - ft_strlen(d->str);
	if (d->precision < d->largeur && d->precision == ft_strlen(d->str))
		j = d->largeur - d->precision - 1;
	return (j);
}

int	aff_j_int_2(t_flags *d)
{
	int j;

	j = 0;
	if (d->precision > d->largeur)
		j = 0;
	if (d->precision < d->largeur && d->precision > ft_strlen(d->str))
		j = d->largeur - d->precision;
	if (d->precision < d->largeur && d->precision < ft_strlen(d->str))
		j = d->largeur - ft_strlen(d->str);
	if (d->precision < d->largeur && d->precision == ft_strlen(d->str))
		j = d->largeur - d->precision;
	return (j);
}
