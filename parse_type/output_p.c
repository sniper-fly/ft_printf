/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:07:26 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 11:05:42 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				output_p(t_flags *flags, va_list argptr)
{
	unsigned long	address;
	void			*ptr;
	int				actual_numlen;
	int				actual_width;

	ptr = va_arg(argptr, void*);
	address = (unsigned long)ptr;
	actual_numlen = MAX(count_digits_u_long16base(address), flags->precision);
	actual_numlen += 2; //0xの分を足す
	if (address == 0 && flags->pre_exist == 1 && flags->precision == 0)
		actual_numlen = 2;
	actual_width = MAX(actual_numlen, flags->width);
	flags->total_output_len += actual_width;
	if (flags->minus_flag)
	{
		ft_putstr_fd("0x", 1);
		put_u_long16base(address, flags->pre_exist, flags->precision, "0123456789abcdef");
		put_it_xx_times(' ', actual_width - actual_numlen);
	}
	else if (flags->fill_zero_flag)
	{
		if (flags->pre_exist == 1)
		{
			put_it_xx_times(' ', actual_width - actual_numlen);
			ft_putstr_fd("0x", 1);
			put_u_long16base(address, flags->pre_exist, flags->precision, "0123456789abcdef");
		}
		else
		{
			ft_putstr_fd("0x", 1);
			put_it_xx_times(' ', actual_width - actual_numlen);
			ft_putnbr_u_long16base(address, "0123456789abcdef");
		}
	}
	else
	{
		put_it_xx_times(' ', actual_width - actual_numlen);
		ft_putstr_fd("0x", 1);
		put_u_long16base(address, flags->pre_exist, flags->precision, "0123456789abcdef");
	}
}