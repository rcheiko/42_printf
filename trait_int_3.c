/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_int_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:33:18 by rcheiko           #+#    #+#             */
/*   Updated: 2021/03/10 15:40:20 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	traitement_int_2(t_flags *d, int i)
{
	if (d->str[0] == '-')
	{
		if (d->precision < ft_strlen(d->str) && d->largeur < ft_strlen(d->str))
			i = affichage_int_global(d);
		else if (d->zero && !d->minus && d->precision < 0)
			i = affichage_int_1_zero(d);
		else if (d->minus)
			i = affichage_int_1_minus(d);
		else if (!d->minus)
			i = affichage_int_1(d);
	}
	else if (d->str[0] != '-')
	{
		if (d->precision < ft_strlen(d->str) && d->largeur < ft_strlen(d->str))
			i = affichage_int_global(d);
		else if (d->zero && !d->minus && d->precision < 0)
			i = affichage_int_2_zero(d);
		else if (d->minus)
			i = affichage_int_2_minus(d);
		else if (!d->minus)
			i = affichage_int_2(d);
	}
	return (i);
}
