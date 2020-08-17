/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:04:53 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 12:14:32 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				output_c(t_flags *flags, va_list argptr)
{
	int		actual_width;
	int		ch;

	ch = va_arg(argptr, int);
	actual_width = MAX(1, flags->width);
	flags->total_output_len += actual_width;
	if (flags->minus_flag == 1)
	{
		write(1, &ch, 1);
		put_it_xx_times(' ', actual_width - 1);
	}
	else if (flags->fill_zero_flag == 1)
	{
		put_it_xx_times('0', actual_width - 1);
		write(1, &ch, 1);
	}
	else
	{
		put_it_xx_times(' ', actual_width - 1);
		write(1, &ch, 1);
	}
}
