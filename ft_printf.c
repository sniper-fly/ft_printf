/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 10:23:55 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/17 12:10:38 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_PRINTF_C
#include "ft_printf.h"

int			ft_printf(const char *fmt, ...)
{
	va_list	argptr;
	t_flags	flags;

	va_start(argptr, fmt);
	init_flags_except_total_len(&flags);
	flags.total_output_len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			init_flags_except_total_len(&flags);
			fmt++;
			parse_fmt(&flags, &fmt, argptr);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			flags.total_output_len++;
			fmt++;
		}
	}
	va_end(argptr);
	return (flags.total_output_len);
}

static void	parse_fmt(t_flags *flags, const char **fmt, va_list argptr)
{
	set_zero_minus_flag(flags, fmt);
	if (is_from1to9(**fmt) == 1)
		set_width(flags, fmt);
	else if (**fmt == '*')
		set_width_asterisk(flags, fmt, argptr);
	if (**fmt == '.')
	{
		set_precision_flag(flags, fmt);
		if (is_from0to9(**fmt) == 1)
			set_precision(flags, fmt);
		else if (**fmt == '*')
			set_precision_asterisk(flags, fmt, argptr);
	}
	parse_type(flags, fmt, argptr);
}

static void	init_flags_except_total_len(t_flags *flags)
{
	flags->fill_zero_flag = 0;
	flags->minus_flag = 0;
	flags->width = 0;
	flags->pre_exist = 0;
	flags->precision = 0;
}

static int	is_from1to9(char num)
{
	if ('1' <= num && num <= '9')
		return (1);
	else
		return (0);
}

static int	is_from0to9(char num)
{
	if ('0' <= num && num <= '9')
		return (1);
	else
		return (0);
}
