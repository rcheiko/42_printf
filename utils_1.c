/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:05:36 by rcheiko           #+#    #+#             */
/*   Updated: 2021/03/10 15:11:21 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int		ft_putchar(char c, int i)
{
	write(1, &c, 1);
	return (i + 1);
}

void	ft_putchar_s(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
		ft_putchar_s(*str++);
}
