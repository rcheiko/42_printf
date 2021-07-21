/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:38:03 by rcheiko           #+#    #+#             */
/*   Updated: 2021/05/20 12:28:06 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags
{
	int		zero;
	int		minus;
	int		point;
	int		largeur;
	int		precision;
	char	type;
	char	c;
	char	*str;
	char	*result;

}				t_flags;

char			ft_isdigit(int c);
int				ft_strlen(const char *str);
int				ft_putchar(char c, int i);
void			ft_putchar_s(char c);
void			ft_putstr(char *str);
void			ft_putstr_i(char *str, int i);
int				ft_putnstr(char *str, int len);
int				ft_putstr_count(char *str, int len);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
char			*ft_strdup(const char *s1);
int				fill_struc_min_zero(t_flags *d, const char *format, int i);
int				fill_struc_larg(t_flags *d, const char *format,
				va_list arg, int i);
void			fill_struc_dot(t_flags *d, const char *format, int i);
int				fill_struc_preci(t_flags *d, const char *format,
				va_list arg, int i);
char			*print_unsigned_base(unsigned long nb, char *base);
int				get_size_base(unsigned long nb, char *base);
void			aff_cs(t_flags *d, const char *format, va_list arg, int i);
void			aff_x(t_flags *d, const char *format, va_list arg, int i);
void			aff_diu(t_flags *d, const char *format, va_list arg, int i);
void			aff_p(t_flags *d, const char *format, va_list arg, int i);
int				size_int(int a);
char			*ft_rev(char *str);
char			*ft_itoa_minus(unsigned int n);
char			*ft_itoa(int n);
int				traitement_int(t_flags *d);
int				traitement_int_2(t_flags *d, int i);
int				affichage_int_1(t_flags *d);
int				affichage_int_global(t_flags *d);
int				affichage_int_1_zero(t_flags *d);
int				affichage_int_1_minus(t_flags *d);
int				affichage_int_2_minus(t_flags *d);
int				affichage_int_2(t_flags *d);
int				affichage_int_2_zero(t_flags *d);
int				traitement_p(t_flags *d);
int				affichage_p_minus(t_flags *d);
int				affichage_p(t_flags *d);
int				traitement_s(t_flags *d);
int				affichage_s_1_minus(t_flags *d);
int				affichage_s_1(t_flags *d);
int				affichage_s_2_minus(t_flags *d);
int				affichage_s_2(t_flags *d);
int				aff_j_int_1(t_flags *d);
int				aff_j_int_2(t_flags *d);
int				traitement_c(t_flags *d);
int				traitement_pourc(t_flags *d);
void			init_struct(t_flags *d);
int				ft_printf(const char *format, ...);
int				traitement(const char *format, t_flags *d, va_list arg, int i);
int				aff_result(t_flags *d, int to);
#endif
