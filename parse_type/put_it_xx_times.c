/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_it_xx_times.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:38:27 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/13 18:41:17 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				put_it_xx_times(char ch, int times)
{
	int count;
	
	count = 0;
	while (count < times)
	{
		write(1, &ch, 1);
		count++;
	}
}