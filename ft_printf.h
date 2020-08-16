/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 10:26:56 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/16 14:06:50 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ABS(x) (x >= 0 ? x : -(x))
# define MIN(x, y) (x <= y ? x : y)
# define MAX(x, y) (x >= y ? x : y)

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct {
	int		fill_zero_flag;
	int		minus_flag;
	int		width;
	int		precision_exsistence;
	int		precision;
	int		total_output_len;
}					t_flags;


int					ft_printf(const char *fmt, ...);
void				set_zero_minus_flag(t_flags *flags, const char **fmt);
void				set_width(t_flags *flags, const char **fmt);
void				set_width_asterisk
					(t_flags *flags, const char **fmt, va_list argptr);
void				set_precision_flag(t_flags *flags, const char **fmt);
void				set_precision(t_flags *flags, const char **fmt);
void				set_precision_asterisk
					(t_flags *flags, const char **fmt, va_list argptr);
void				parse_type(t_flags *flags, const char **fmt, va_list argptr);
void				output_c(t_flags *flags, va_list argptr);
void				output_s(t_flags *flags, va_list argptr);
void				output_p(t_flags *flags, va_list argptr);
void				output_di(t_flags *flags,va_list argptr);
void				output_u(t_flags *flags, va_list argptr);
void				output_x(t_flags *flags, va_list argptr);
void				output_X(t_flags *flags, va_list argptr);
void				output_percent(t_flags *flags);
void				put_it_xx_times(char ch, int times);
int					count_digits_int10(int num);
int					count_digits_u_int10(unsigned int num);
int					count_digits_u_int16base(unsigned int num);
unsigned long		count_digits_u_long16base(unsigned long num);
void				put_int10(int num, int precision);
void				put_u_int10(unsigned int num, int precision);
void				put_u_int16base(unsigned int num, int precision, char *base);
void				ft_putnbr_u(unsigned int num);
void				ft_putnbr_u_16base(unsigned int num, char *base);
void				ft_putnbr_u_long16base(unsigned long num, char *base);

#endif