/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:07:46 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 12:14:20 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

void	put_int10(int num, int pre_exist, int precision)
{
	if (num == 0 && pre_exist == 1 && precision == 0)
		return ;
	if (num < 0)
		write(1, "-", 1);
	put_it_xx_times('0', precision - count_digits_int10(num));
	if (num == INT_MIN)
		ft_putstr_fd("2147483648", 1);
	else if (num < 0)
	{
		num *= -1;
		ft_putnbr_fd(num, 1);
	}
	else
	{
		ft_putnbr_fd(num, 1);
	}
}

void	ft_putnbr_u(unsigned int num)
{
	if (num < 10)
	{
		ft_putchar_fd(num + '0', 1);
	}
	else
	{
		ft_putnbr_u(num / 10);
		ft_putchar_fd(num % 10 + '0', 1);
	}
}

void	put_u_int10(unsigned int num, int pre_exist, int precision)
{
	if (num == 0 && pre_exist == 1 && precision == 0)
		return ;
	put_it_xx_times('0', precision - count_digits_u_int10(num));
	ft_putnbr_u(num);
}

void	ft_putnbr_u_16base(unsigned int num, char *base)
{
	if (num < 16)
	{
		ft_putchar_fd(base[num], 1);
	}
	else
	{
		ft_putnbr_u_16base(num / 16, base);
		ft_putchar_fd(base[num % 16], 1);
	}
}

void	put_u_int16base(unsigned int num, int pre_exist,
								int precision, char *base)
{
	if (num == 0 && pre_exist == 1 && precision == 0)
		return ;
	put_it_xx_times('0', precision - count_digits_u_int16base(num));
	ft_putnbr_u_16base(num, base);
}
