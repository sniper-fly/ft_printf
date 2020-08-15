/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:07:46 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/15 12:46:34 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

void		put_int10(int num, int precision)
{
	if (num < 0)
		write(1, "-", 1);
	put_it_xx_times('0', precision - count_digits_int10(num));
	if (num == INT_MIN)
		ft_putstr_fd("2147483648", 1);
	else
	{
		num *= -1;
		ft_putnbr_fd(num, 1);
	}
}