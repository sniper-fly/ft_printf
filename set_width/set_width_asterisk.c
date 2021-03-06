/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_asterisk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:02:41 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 12:26:20 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				set_width_asterisk(t_flags *flags,
						const char **fmt, va_list argptr)
{
	int		tmp_width;

	tmp_width = va_arg(argptr, int);
	if (tmp_width < 0)
	{
		tmp_width *= -1;
		flags->minus_flag = 1;
	}
	flags->width = tmp_width;
	(*fmt)++;
}
