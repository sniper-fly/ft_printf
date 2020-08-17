/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:53:42 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 11:13:46 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

int				count_digits_int10(int num)
{
	int	digits;

	if (num == INT_MIN)
		return (10);
	else if (num < 0)
		num *= -1;
	digits = 1;
	while (num >= 10)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

int				count_digits_u_int10(unsigned int num)
{
	int digits;

	digits = 1;
	while (num >= 10)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

int				count_digits_u_int16base(unsigned int num)
{
	int	digits;

	digits = 1;
	while (num >= 16)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}

int				count_digits_u_long16base(unsigned long num)
{
	int	digits;

	digits = 1;
	while (num >= 16)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}