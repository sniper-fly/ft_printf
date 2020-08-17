/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_asterisk.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:03:28 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 12:03:24 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				set_precision_asterisk(t_flags *flags,
						const char **fmt, va_list argptr)
{
	int		tmp_precision;

	tmp_precision = va_arg(argptr, int);
	if (tmp_precision < 0)
	{
		flags->pre_exist = 0;
	}
	else
	{
		flags->precision = tmp_precision;
	}
	(*fmt)++;
}
