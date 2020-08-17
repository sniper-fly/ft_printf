/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:05:26 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 10:45:46 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			output_s2(t_flags *flags, int actual_strlen,
								int actual_width, char *str);

void				output_s(t_flags *flags, va_list argptr)
{
	char	*str;
	int		actual_strlen;
	int		actual_width;

	str = va_arg(argptr, char*);
	if (str == NULL)
		str = "(null)";
	if (flags->pre_exist == 1)
		actual_strlen = MIN((int)ft_strlen(str), flags->precision);
	else
		actual_strlen = ft_strlen(str);
	actual_width = MAX(actual_strlen, flags->width);
	flags->total_output_len += actual_width;
	output_s2(flags, actual_strlen, actual_width, str);
}

static void			output_s2(t_flags *flags, int actual_strlen,
								int actual_width, char *str)
{
	if (flags->minus_flag == 1)
	{
		write(1, str, actual_strlen);
		put_it_xx_times(' ', actual_width - actual_strlen);
	}
	else if (flags->fill_zero_flag == 1)
	{
		put_it_xx_times('0', actual_width - actual_strlen);
		write(1, str, actual_strlen);
	}
	else
	{
		put_it_xx_times(' ', actual_width - actual_strlen);
		write(1, str, actual_strlen);
	}
}
