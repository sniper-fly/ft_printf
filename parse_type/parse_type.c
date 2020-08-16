/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:03:40 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/16 13:25:39 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				parse_type(t_flags *flags, const char **fmt, va_list argptr)
{
	if (**fmt == 'c')
		output_c(flags, argptr);
	else if (**fmt == 's')
		output_s(flags, argptr);
	else if (**fmt == 'p')
		output_p(flags, argptr);
	else if (**fmt == 'd' || **fmt == 'i')
		output_di(flags, argptr);
	else if (**fmt == 'u')
		output_u(flags, argptr);
	else if (**fmt == 'x')
		output_x(flags, argptr);
	else if (**fmt == 'X')
		output_X(flags, argptr);
	else if (**fmt == '%')
		output_percent(flags);
	else
		return ;
	(*fmt)++;
}