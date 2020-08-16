/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:07:23 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/16 18:28:36 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			output_u2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width);

void				output_u(t_flags *flags, va_list argptr)
{
	int		actual_numlen;
	int		actual_width;
	int		num;

	num = va_arg(argptr, unsigned int);
	actual_numlen = MAX(count_digits_u_int10(num), flags->precision);
	actual_width = MAX(actual_numlen, flags->width);
	flags->total_output_len += actual_width;
	output_u2(flags, num, actual_numlen, actual_width);
}

void				output_u2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width)
{
	if (flags->minus_flag)
	{
		put_u_int10(num, flags->precision);
		put_it_xx_times(' ', actual_width - actual_numlen);
	}
	else if (flags->fill_zero_flag)
	{
		if (flags->pre_exist)
		{
			put_it_xx_times(' ', actual_width - actual_numlen);
			put_u_int10(num, flags->precision);
		}
		else
		{
			put_it_xx_times('0', actual_width - actual_numlen);
			ft_putnbr_u(num);
		}
	}
	else
	{
		put_it_xx_times(' ', actual_width - actual_numlen);
		put_u_int10(num, flags->precision);
	}
}
