/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:04:10 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/14 11:20:21 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				set_precision(t_flags *flags, const char **fmt)
{
	int		total;

	while (**fmt == '0')
		(*fmt)++;
	total = 0;
	while (ft_isdigit(**fmt))
	{
		total = (total * 10) + ((**fmt) - '0');
		(*fmt)++;
	}
	flags->precision = total;
}