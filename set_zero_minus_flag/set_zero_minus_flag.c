/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero_minus_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:01:50 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 12:06:48 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		set_zero_minus_flag(t_flags *flags, const char **fmt)
{
	while (**fmt == '0' || **fmt == '-')
	{
		if (**fmt == '0')
			flags->fill_zero_flag = 1;
		else if (**fmt == '-')
			flags->minus_flag = 1;
		(*fmt)++;
	}
}
