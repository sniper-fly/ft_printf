/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:07:26 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/16 13:58:05 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				output_p(t_flags *flags, va_list argptr)
{
	unsigned long	ptr_address;
	void			*ptr;
	int				actual_numlen;
	int				actual_width;

	// if (flags->precision_exsistence)
	// 	return ;
	ptr = va_arg(argptr, void*);
	ptr_address = (unsigned long)ptr;
	actual_numlen = count_digits_u_long16base(ptr_address) + 2;
	actual_width = MAX(actual_numlen, flags->width);
	flags->total_output_len += actual_width;
	if (flags->minus_flag)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_ulong_16base(ptr_address, "0123456789abcdef");
		put_it_xx_times(' ', actual_width - actual_numlen);
	}
	else if (flags->fill_zero_flag)
		return;
	else
	{
		put_it_xx_times(' ', actual_width - actual_numlen);
		ft_putstr_fd("0x", 1);
		ft_putnbr_ulong_16base(ptr_address, "0123456789abcdef");
	}
}