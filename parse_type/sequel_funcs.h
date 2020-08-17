/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequel_funcs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:34:21 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 11:48:09 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEQUEL_FUNC_H
# define SEQUEL_FUNC_H

#include "../ft_printf.h"

# ifdef OUTPUT_S
static void			output_s2(t_flags *flags, int actual_strlen,
								int actual_width, char *str);
# endif

# ifdef OUTPUT_U
static void			output_u2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width);
# endif

# ifdef OUTPUT_D
static void			output_di2(t_flags *flags, int num,
						int actual_numlen, int actual_width);
# endif

# ifdef OUTPUT_X
static void			output_x2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width);
static void			output_X2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width);
# endif

# ifdef OUTPUT_P
static void			output_p2(t_flags *flags, unsigned long address,
						int actual_numlen, int actual_width, char *base);
static void			put_space_address(t_flags *flags, unsigned long address,
						int actual_numlen, int actual_width, char *base);
# endif

#endif