/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:02:23 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/14 11:19:44 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void				set_width(t_flags *flags, const char **fmt)
{
	int		total;

	total = 0;
	while (ft_isdigit(**fmt))
	{
		total = (total * 10) + ((**fmt) - '0');
		(*fmt)++;
	}
	flags->width = total;
}