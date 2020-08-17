/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequel_funcs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:34:21 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 13:29:00 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEQUEL_FUNCS_H
# define SEQUEL_FUNCS_H

# include "../ft_printf.h"

# ifdef OUTPUT_S_C

static void			output_s2(t_flags *flags, int actual_strlen,
								int actual_width, char *str);

# endif

# ifdef OUTPUT_U_C

static void			output_u2(t_flags *flags, unsigned int num,
						int actual_numlen, int actual_width);

# endif

# ifdef OUTPUT_DI_C

static void			output_di2(t_flags *flags, int num,
						int actual_numlen, int actual_width);

# endif

# ifdef OUTPUT_X_C

static void			output_x2(t_flags *flags, unsigned int num,
						int actual_width_minus_numlen, char *base);
static void			output_largex2(t_flags *flags, unsigned int num,
						int actual_width_minus_numlen, char *base);

# endif

# ifdef OUTPUT_P_C

static void			output_p2(t_flags *flags, unsigned long address,
						int actual_width_minus_numlen, char *base);
static void			put_space_address(t_flags *flags, unsigned long address,
						int actual_width_minus_numlen, char *base);

# endif

#endif
