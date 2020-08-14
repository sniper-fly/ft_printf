/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero_minus_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:01:50 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/14 11:18:11 by rnakai           ###   ########.fr       */
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

// static void	init_flags(t_flags *flags)
// {
// 	flags->fill_zero_flag = 0;
// 	flags->minus_flag = 0;
// 	flags->width = 0;
// 	flags->precision_exsistence = 0;
// 	flags->precision = 0;
// 	flags->total_output_len = 0;
// }

// #include <stdio.h>

// int		main(void)
// {
// 	char *hoge = "0--00-0--0-1234";
// 	t_flags flg;

// 	init_flags(&flg);
// 	set_zero_minus_flag(&flg, &hoge);
// 	printf("%s", hoge);
// 	printf("\n");
// 	printf("%d, %d, %d", flg.minus_flag, flg.fill_zero_flag, flg.precision);
// 	return (0);
// }
