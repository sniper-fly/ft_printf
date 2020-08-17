/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:07:20 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 12:30:04 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define OUTPUT_X_C
#include "sequel_funcs.h"

void				output_x(t_flags *flags, va_list argptr)
{
	int				actual_numlen;
	int				actual_width;
	unsigned int	num;
	char			*base;

	base = "0123456789abcdef";
	num = va_arg(argptr, unsigned int);
	actual_numlen = MAX(count_digits_u_int16base(num), flags->precision);
	if (num == 0 && flags->pre_exist == 1 && flags->precision == 0)
		actual_numlen = 0;
	actual_width = MAX(actual_numlen, flags->width);
	flags->total_output_len += actual_width;
	output_x2(flags, num, actual_numlen, actual_width, base);
}

static void			output_x2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width, char *base)
{
	if (flags->minus_flag)
	{
		put_u_int16base(num, flags->pre_exist, flags->precision, base);
		put_it_xx_times(' ', actual_width - actual_numlen);
	}
	else if (flags->fill_zero_flag)
	{
		if (flags->pre_exist)
		{
			put_it_xx_times(' ', actual_width - actual_numlen);
			put_u_int16base(num, flags->pre_exist, flags->precision, base);
		}
		else
		{
			put_it_xx_times('0', actual_width - actual_numlen);
			ft_putnbr_u_16base(num, base);
		}
	}
	else
	{
		put_it_xx_times(' ', actual_width - actual_numlen);
		put_u_int16base(num, flags->pre_exist, flags->precision, base);
	}
}

void				output_largex(t_flags *flags, va_list argptr)
{
	int				actual_numlen;
	int				actual_width;
	unsigned int	num;
	char			*base;

	base = "0123456789ABCDEF";
	num = va_arg(argptr, unsigned int);
	actual_numlen = MAX(count_digits_u_int16base(num), flags->precision);
	if (num == 0 && flags->pre_exist == 1 && flags->precision == 0)
		actual_numlen = 0;
	actual_width = MAX(actual_numlen, flags->width);
	flags->total_output_len += actual_width;
	output_largex2(flags, num, actual_numlen, actual_width, base);
}

static void			output_largex2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width, char *base)
{
	if (flags->minus_flag)
	{
		put_u_int16base(num, flags->pre_exist, flags->precision, base);
		put_it_xx_times(' ', actual_width - actual_numlen);
	}
	else if (flags->fill_zero_flag)
	{
		if (flags->pre_exist)
		{
			put_it_xx_times(' ', actual_width - actual_numlen);
			put_u_int16base(num, flags->pre_exist, flags->precision, base);
		}
		else
		{
			put_it_xx_times('0', actual_width - actual_numlen);
			ft_putnbr_u_16base(num, base);
		}
	}
	else
	{
		put_it_xx_times(' ', actual_width - actual_numlen);
		put_u_int16base(num, flags->pre_exist, flags->precision, base);
	}
}
