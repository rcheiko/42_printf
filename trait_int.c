/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:00:57 by rcheiko           #+#    #+#             */
/*   Updated: 2021/03/10 15:38:27 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	traitement_int(t_flags *d)
{
	int i;

	i = 0;
	return (i = traitement_int_2(d, i));
}

int	affichage_int_global(t_flags *d)
{
	ft_putstr(d->str);
	return (ft_strlen(d->str));
}

int	affichage_int_1_zero(t_flags *d)
{
	int i;
	int j;

	i = 0;
	j = -1;
	i = ft_putchar('-', i);
	while (++j < d->largeur - ft_strlen(d->str))
		i = ft_putchar('0', i);
	ft_putstr_i(d->str, 1);
	i += ft_strlen(d->str) - 1;
	return (i);
}

int	affichage_int_1_minus(t_flags *d)
{
	int i;
	int j;
	int cpt;

	i = 0;
	j = 0;
	cpt = -1;
	if (d->precision > 0)
		j = aff_j_int_1(d);
	if (d->precision <= 0)
		j = d->largeur - ft_strlen(d->str);
	i = ft_putchar('-', i);
	while (++cpt < d->precision - (ft_strlen(d->str) - 1))
		i = ft_putchar('0', i);
	i += ft_strlen(d->str) - 1;
	ft_putstr_i(d->str, 1);
	cpt = -1;
	while (++cpt < j)
		i = ft_putchar(' ', i);
	return (i);
}

int	affichage_int_1(t_flags *d)
{
	int i;
	int j;
	int cpt;

	i = 0;
	j = 0;
	cpt = -1;
	if (d->precision > 0)
		j = aff_j_int_1(d);
	if (d->precision <= 0)
		j = d->largeur - ft_strlen(d->str);
	while (++cpt < j)
		i = ft_putchar(' ', i);
	i = ft_putchar('-', i);
	cpt = -1;
	while (++cpt < d->precision - (ft_strlen(d->str) - 1))
		i = ft_putchar('0', i);
	i += ft_strlen(d->str) - 1;
	ft_putstr_i(d->str, 1);
	return (i);
}
