/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:36:46 by pmontiel          #+#    #+#             */
/*   Updated: 2021/03/10 12:29:55 by pmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		traitement_c(t_flags *d)
{
	int i;

	i = 0;
	if (d->largeur < 1)
		i = ft_putchar(d->c, i);
	else if (d->minus)
	{
		i = ft_putchar(d->c, i);
		while (i < d->largeur)
			i = ft_putchar(' ', i);
	}
	else if (!d->minus && !d->zero)
	{
		while (i < d->largeur - 1)
			i = ft_putchar(' ', i);
		i = ft_putchar(d->c, i);
	}
	return (i);
}

int		traitement_pourc(t_flags *d)
{
	int i;

	i = 0;
	if (!d->minus && d->zero)
	{
		while (i < d->largeur - 1)
			i = ft_putchar('0', i);
		i = ft_putchar(d->c, i);
	}
	return (i);
}
