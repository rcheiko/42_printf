/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:18:06 by pmontiel          #+#    #+#             */
/*   Updated: 2021/03/10 15:37:44 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		traitement_p(t_flags *d)
{
	int i;

	i = 0;
	if (d->minus)
	{
		if (d->largeur < ft_strlen(d->str))
			i = affichage_int_global(d);
		else
			i = affichage_p_minus(d);
	}
	else if (!d->minus)
		i = affichage_p(d);
	return (i);
}

int		affichage_p_minus(t_flags *d)
{
	int i;
	int j;

	i = 0;
	j = 2;
	i = ft_putstr_count("0x", i);
	i = ft_putstr_count(d->str, i);
	while (j < d->largeur - ft_strlen(d->str))
	{
		i = ft_putchar(' ', i);
		j++;
	}
	return (i);
}

int		affichage_p(t_flags *d)
{
	int i;
	int j;

	i = 0;
	j = 2;
	while (j < d->largeur - ft_strlen(d->str))
	{
		i = ft_putchar(' ', i);
		j++;
	}
	i = ft_putstr_count("0x", i);
	i = ft_putstr_count(d->str, i);
	return (i);
}
