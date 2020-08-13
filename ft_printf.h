/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 10:26:56 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/13 10:50:54 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ABS(x) (x >= 0 ? x : -(x))
# define MIN(x, y) (x <= y ? x : y)
# define MAX(x, y) (x >= y ? x : y)

# include <stdarg.h>
# include 

typedef struct {
	int		fill_zero_flag;
	int		minus_flag;
	int		width;
	int		precision_exsistence;
	int		precision;
	int		total_output_len;
}					t_flags;


int					ft_printf(char *fmt, ...);

#endif