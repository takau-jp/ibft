/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:51:16 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:17:58 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>
# include <float.h>
# include <stdint.h>
# include <inttypes.h>

# include "libft.h"

# define CONV "cspdiuxX\%onfFeEgGaA"
# define FLAGS "-+ #0"
# define LENGTH "hljz"
# define DB_FRAC 1075
# define DB_INT 309
# define DB_FRAC_HEX 269

typedef struct s_print
{
	int		res;
	char	*buf;
}	t_print;

typedef struct s_conv
{
	char	hash_flag;
	char	space_flags;
	char	sign_flags;
	int		width;
	bool	has_prec;
	int		prec;
	char	prec_arg;
	char	length[3];
	char	c;
}	t_conv;

typedef struct s_mydb
{
	uint8_t		sign;
	uint16_t	exp;
	uint64_t	frac;
	uint64_t	frac_bin;
	uint64_t	int_bin;
	int8_t		decimal_int[DB_INT];
	int8_t		decimal_frac[DB_FRAC];
}	t_mydb;

int				ft_printf(const char *format, ...);
char			*ft_read_conversion(t_conv *conv, va_list *ap, char *itr);
int				ft_atoi_width(const char *str);
bool			ft_is_longer(t_conv *conv, char *itr);
int				ft_put_conversion(t_print *print, t_conv *conv, va_list *ap);
bool			ft_conv_len(t_conv *conv, va_list *ap, intmax_t *num);
bool			ft_conv_ulen(t_conv *conv, va_list *ap, uintmax_t *num);
int				ft_conv_a(t_print *print, t_conv *conv, va_list *ap);
void			convert_double_hex(t_conv *conv, t_mydb *mydouble);
int				print_mydouble_a(t_conv *conv, t_mydb *mydouble, int exponent);
int				ft_conv_c(t_print *print, t_conv *conv, va_list *ap);
int				ft_conv_d(t_print *print, t_conv *conv, va_list *ap);
int				ft_conv_p(t_print *print, t_conv *conv, va_list *ap);
int				ft_conv_u(t_print *print, t_conv *conv, va_list *ap);
int				ft_conv_s(t_print *print, t_conv *conv, va_list *ap);
int				ft_conv_x(t_print *print, t_conv *conv, va_list *ap);
int				ft_conv_percent(t_print *print, t_conv *conv);
int				ft_conv_o(t_print *print, t_conv *conv, va_list *ap);
int				ft_conv_f(t_print *print, t_conv *conv, va_list *ap);
int				ft_double_sp_case(t_print *print, t_conv *conv, double num);
void			get_binary_double(t_mydb *mydouble, double num);
bool			convert_double(t_conv *conv, t_mydb *mydouble);
void			convert_int(t_mydb *mydouble);
void			convert_frac(t_mydb *mydouble);
bool			frac_round(t_conv *conv, t_mydb *mydouble);
int				ft_get_digits_double(t_conv *conv, t_mydb mydouble);
int				print_mydouble(t_conv *conv, t_mydb *mydouble);
int				ft_conv_g(t_print *print, t_conv *conv, va_list *ap);
void			ft_prec_minus_g(t_conv *conv, int num);
int				ft_conv_ge(t_print *print, t_conv *conv, double num);
int				ft_get_len_ge(t_conv *conv, t_mydb *mydouble, int exponent);
int				ft_put_ge(t_conv *conv, t_mydb *mydouble, int len, int exp);
int				print_mydouble_ge(t_conv *conv, t_mydb *mydouble, int exponent);
int				ft_conv_gf(t_print *print, t_conv *conv, double num);
int				ft_put_gf(t_conv *conv, t_mydb *mydouble, int len);
int				print_mydouble_gf(t_conv *conv, t_mydb *mydouble);
int				ft_conv_n(t_print *print, va_list *ap);
int				ft_put_lower_hexa(unsigned int num, int padding);
int				ft_put_upper_hexa(unsigned int num, int padding);
int				ft_conv_e(t_print *print, t_conv *conv, va_list *ap);
int				ft_get_exp(t_mydb *mydouble);
void			convert_double_simple(t_mydb *mydouble);
bool			convert_double_e(t_conv *conv, t_mydb *mydouble, int exp);
bool			frac_round_e(t_conv *conv, t_mydb *mydouble);
bool			frac_move_up_e(t_conv *conv, t_mydb *mydouble);
int				ft_get_digits_double_e(t_conv *conv, t_mydb mydouble);
int				print_mydouble_e(t_conv *conv, t_mydb *mydouble, int exponent);
int				ft_conv_d_len(t_print *print, t_conv *conv, va_list *ap);
int				ft_conv_u_len(t_print *print, t_conv *conv, va_list *ap);
int				ft_conv_n_len(t_print *print, t_conv *conv, va_list *ap);
int				ft_conv_x_len(t_print *print, t_conv *conv, va_list *ap);
int				ft_put_lower_hexa_len(uintmax_t num, int padding);
int				ft_put_upper_hexa_len(uintmax_t num, int padding);
int				ft_conv_o_len(t_print *print, t_conv *conv, va_list *ap);
int				ft_put_width_space(t_conv *conv, size_t len);
int				ft_put_width_zero(t_conv *conv, size_t len);
int				ft_get_digits(int n, int base);
int				ft_get_digits_uint(unsigned int n, int base);
int				ft_get_digits_uintptr(uintptr_t n, int base);
int				ft_get_digits_intmax(intmax_t n, int base);
int				ft_get_digits_uintmax(uintmax_t n, int base);
void			array_add(int8_t *a, int8_t *b, int size);
void			array_half(int8_t *n, int size);
void			array_double(int8_t *n, int size);
void			array_add_hex(int8_t *a, int8_t *b, int size);
void			array_half_hex(int8_t *n, int size);
void			array_double_hex(int8_t *n, int size);
char			*ft_join_char(char *buf, char c);
int				ft_print(char *itr, t_print *print, t_conv *conv, va_list *ap);
bool			ft_print_buf(t_print *print, t_conv *conv, int len);
uintmax_t		ft_abs_intmax(intmax_t i);
int				ft_putchar(char c);
size_t			ft_putstr(char *str);
size_t			ft_putstrl(char *str, size_t len);
int				ft_putnbr(int n);
int				ft_strcmp(const char *s1, const char *s2);

#endif
