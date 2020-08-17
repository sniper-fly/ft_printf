/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:07:26 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 12:28:27 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define OUTPUT_P_C
#include "sequel_funcs.h"

void				output_p(t_flags *flags, va_list argptr)
{
	unsigned long	address;
	void			*ptr;
	int				actual_numlen;
	int				actual_width;
	char			*base;

	base = "0123456789abcdef";
	ptr = va_arg(argptr, void*);
	address = (unsigned long)ptr;
	actual_numlen = MAX(count_digits_u_long16base(address), flags->precision);
	actual_numlen += 2;
	if (address == 0 && flags->pre_exist == 1 && flags->precision == 0)
		actual_numlen = 2;
	actual_width = MAX(actual_numlen, flags->width);
	flags->total_output_len += actual_width;
	output_p2(flags, address, actual_numlen, actual_width, base);
}

static void			output_p2(t_flags *flags, unsigned long address,
						int actual_numlen, int actual_width, char *base)
{
	if (flags->minus_flag)
	{
		ft_putstr_fd("0x", 1);
		put_u_long16base(address, flags->pre_exist, flags->precision, base);
		put_it_xx_times(' ', actual_width - actual_numlen);
	}
	else if (flags->fill_zero_flag)
	{
		if (flags->pre_exist == 1)
		{
			put_space_address(flags, address, actual_numlen,
								actual_width, base);
		}
		else
		{
			ft_putstr_fd("0x", 1);
			put_it_xx_times(' ', actual_width - actual_numlen);
			ft_putnbr_u_long16base(address, base);
		}
	}
	else
		put_space_address(flags, address, actual_numlen, actual_width, base);
}

static void			put_space_address(t_flags *flags, unsigned long address,
						int actual_numlen, int actual_width, char *base)
{
	put_it_xx_times(' ', actual_width - actual_numlen);
	ft_putstr_fd("0x", 1);
	put_u_long16base(address, flags->pre_exist, flags->precision, base);
}
