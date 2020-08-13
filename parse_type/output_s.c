/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:05:26 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/13 22:04:22 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				output_s(t_flags *flags, va_list argptr)
{
	char	*str;
	int		actual_strlen;
	int		actual_width;

	str = va_arg(argptr, char*);
	if (str == NULL)
		str = "(null)";
	if (flags->precision_exsistence == 1)
		actual_strlen = MIN(ft_strlen(str), flags->precision);
	else
		actual_strlen = ft_strlen(str);
	actual_width = MAX(actual_strlen, flags->width);
	if (flags->minus_flag == 1)
	{
		write(1, str, actual_strlen);
		put_it_xx_times(' ', actual_width - actual_strlen);
	}
	else if (flags->minus_flag == 1)
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
