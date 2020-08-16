/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 13:51:29 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/16 13:53:50 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_ulong_16base(unsigned long num, char *base)
{
	if (num < 16)
	{
		ft_putchar_fd(base[num], 1);
	}
	else
	{
		ft_putnbr_ul_16base(num / 16, base);
		ft_putchar_fd(base[num % 16], 1);
	}
}
