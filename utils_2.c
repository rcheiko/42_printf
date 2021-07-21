/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:06:30 by rcheiko           #+#    #+#             */
/*   Updated: 2021/03/10 14:26:54 by pmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[len] = src[i];
		i++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*rep;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	if (!(rep = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[i])
	{
		rep[i] = s1[i];
		i++;
	}
	rep[i] = '\0';
	return (rep);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_putnstr(char *str, int len)
{
	int i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar_s(str[i]);
		i++;
	}
	return (i);
}

int		ft_putstr_count(char *str, int len)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar_s(str[i]);
		i++;
		len++;
	}
	return (len);
}
