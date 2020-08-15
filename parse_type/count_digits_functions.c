/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:53:42 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/15 12:39:03 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

int			count_digits_int10(int num)
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

// int			count_digits_u_int10(int num)
// {
// 	unsigned int number;

// 	number = (unsigned int)num;
	
// }