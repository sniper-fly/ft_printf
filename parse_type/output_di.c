/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:07:14 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 11:48:49 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define OUTPUT_D
#include "sequel_funcs.h"
#include <limits.h>

void				output_di(t_flags *flags, va_list argptr)
{
	int		actual_numlen;
	int		actual_width;
	int		num;

	num = va_arg(argptr, int);
	actual_numlen = MAX(count_digits_int10(num), flags->precision);
	if (num == 0 && flags->pre_exist == 1 && flags->precision == 0)
		actual_numlen = 0;
	actual_numlen += (num < 0) ? 1 : 0;
	// if (num < 0) // マイナス記号が入るため
	// 	actual_numlen++;
	actual_width = MAX(actual_numlen, flags->width);
	flags->total_output_len += actual_width;
	if (flags->minus_flag == 1)
	{
		put_int10(num, flags->pre_exist, flags->precision);
		put_it_xx_times(' ', actual_width - actual_numlen);
	}
	else if (flags->fill_zero_flag == 1)
	{
		output_di2(flags, num, actual_numlen, actual_width);
	}
	else
	{
		put_it_xx_times(' ', actual_width - actual_numlen);
		put_int10(num, flags->pre_exist, flags->precision);
	}
}

static void			output_di2(t_flags *flags, int num,
						int actual_numlen, int actual_width)
{
	if (flags->pre_exist)
	{
		put_it_xx_times(' ', actual_width - actual_numlen);
		put_int10(num, flags->pre_exist, flags->precision);
	}
	else
	{
		if (num < 0)
		{
			write(1, "-", 1);
			put_it_xx_times('0', actual_width - actual_numlen);
			if (num == INT_MIN)
				ft_putstr_fd("2147483648", 1);
			else
			{
				num *= -1;
				ft_putnbr_fd(num, 1);
			}
		}
		else
		{
			put_it_xx_times('0', actual_width - actual_numlen);
			ft_putnbr_fd(num, 1);
		}
	}
}
