/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:06:52 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 12:07:31 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				output_percent(t_flags *flags)
{
	int		actual_width;

	actual_width = MAX(1, flags->width);
	flags->total_output_len += actual_width;
	if (flags->minus_flag == 1)
	{
		write(1, "%", 1);
		put_it_xx_times(' ', actual_width - 1);
	}
	else if (flags->fill_zero_flag == 1)
	{
		put_it_xx_times('0', actual_width - 1);
		write(1, "%", 1);
	}
	else
	{
		put_it_xx_times(' ', actual_width - 1);
		write(1, "%", 1);
	}
}
