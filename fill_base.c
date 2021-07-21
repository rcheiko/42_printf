/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:51:07 by rcheiko           #+#    #+#             */
/*   Updated: 2021/03/09 12:51:18 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*print_unsigned_base(unsigned long nb, char *base)
{
	int				i;
	char			*result;

	i = 0;
	if (!(result = malloc(sizeof(char) * get_size_base(nb, base) + 1)))
		return (NULL);
	if (nb == 0)
		result[i++] = '0';
	while (nb > 0)
	{
		result[i] = base[nb % 16];
		i++;
		nb /= 16;
	}
	result[i] = 0;
	return (ft_rev(result));
}

int			get_size_base(unsigned long nb, char *base)
{
	int				count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb > 0)
	{
		count++;
		nb /= ft_strlen(base);
	}
	return (count);
}
