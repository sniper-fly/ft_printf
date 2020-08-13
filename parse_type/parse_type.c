/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:03:40 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/13 18:02:50 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				parse_type(t_flags *flags, char **fmt)
{
	if (**fmt == 'c')
		output_c(flags, fmt);
	else if (**fmt == 's')
		output_s(flags, fmt);
	else if (**fmt == 'p')
		output_p(flags, fmt);
	else if (**fmt == 'd' || **fmt == 'i')
		output_di(flags, fmt);
	else if (**fmt == 'u')
		output_u(flags, fmt);
	else if (**fmt == 'x')
		output_x(flags, fmt);
	else if (**fmt == 'X')
		output_X(flags, fmt);
	else if (**fmt == '%')
		output_percent(flags, fmt);
	else
	{
		(*fmt)++;
	}
}