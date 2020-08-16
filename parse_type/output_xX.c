/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:07:20 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/16 13:08:15 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			output_x2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width);
static void			output_X2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width);

void				output_x(t_flags *flags, va_list argptr)
{
	int				actual_numlen;
	int				actual_width;
	unsigned int	num;

	num = va_arg(argptr, unsigned int);
	actual_numlen = MAX(count_digits_u_int16base(num), flags->precision);
	actual_width = MAX(actual_numlen, flags->width);
	flags->total_output_len += actual_width;
	output_x2(flags, num, actual_numlen, actual_width);
}

static void			output_x2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width)
{
	if (flags->minus_flag)
	{
		put_u_int16base(num, flags->precision, "0123456789abcdef");
		put_it_xx_times(' ', actual_width - actual_numlen);
	}
	else if (flags->fill_zero_flag)
	{
		if (flags->precision_exsistence)
		{
			put_it_xx_times(' ', actual_width - actual_numlen);
			put_u_int16base(num, flags->precision, "0123456789abcdef");
		}
		else
		{
			put_it_xx_times('0', actual_width - actual_numlen);
			ft_putnbr_u_16base(num, "0123456789abcdef");
		}
	}
	else
	{
		put_it_xx_times(' ', actual_width - actual_numlen);
		put_u_int16base(num, flags->precision, "0123456789abcdef");
	}
}

void				output_X(t_flags *flags, va_list argptr)
{
	int				actual_numlen;
	int				actual_width;
	unsigned int	num;

	num = va_arg(argptr, unsigned int);
	actual_numlen = MAX(count_digits_u_int16base(num), flags->precision);
	actual_width = MAX(actual_numlen, flags->width);
	flags->total_output_len += actual_width;
	output_x2(flags, num, actual_numlen, actual_width);
}

static void			output_X2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width)
{
	if (flags->minus_flag)
	{
		put_u_int16base(num, flags->precision, "0123456789ABCDEF");
		put_it_xx_times(' ', actual_width - actual_numlen);
	}
	else if (flags->fill_zero_flag)
	{
		if (flags->precision_exsistence)
		{
			put_it_xx_times(' ', actual_width - actual_numlen);
			put_u_int16base(num, flags->precision, "0123456789ABCDEF");
		}
		else
		{
			put_it_xx_times('0', actual_width - actual_numlen);
			ft_putnbr_u_16base(num, "0123456789ABCDEF");
		}
	}
	else
	{
		put_it_xx_times(' ', actual_width - actual_numlen);
		put_u_int16base(num, flags->precision, "0123456789ABCDEF");
	}
}
