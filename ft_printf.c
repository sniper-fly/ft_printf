/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 10:23:55 by rnakai            #+#    #+#             */
/*   Updated: 2020/08/13 12:20:50 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//1文字ずつ画面に出力し、%が来たらフォーマットを解析する

#include "ft_printf.h"

static void	init_flags(void *ptr, size_t size);
static int	is_from0to9(char num);
static int	is_from1to9(char num);
static void	parse_fmt(t_flags *flags, char *fmt, va_list argptr);

int			ft_printf(const char *fmt, ...)
{
	va_list	argptr;
	t_flags	*flags;

	va_start(argptr, fmt);
	init_flags(flags, sizeof(t_flags));
	while (*fmt)
	{
		if (*fmt == '%')
		{
			parse_fmt(flags, fmt, argptr);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			flags->total_output_len++;
			fmt++;
		}
	}
	va_end(argptr);
	return (flags->total_output_len);
}

static void	parse_fmt(t_flags *flags, char *fmt, va_list argptr)
{
	set_zero_minus_flag(flags, fmt);
	if (is_from1to9(*fmt) == 1)
		set_width(flags, fmt);
	else if (*fmt == '*')
		set_width_asterisk(flags, fmt, argptr);
	if (*fmt == '.')
	{
		set_precision_flag(flags);
		if (is_from0to9(*fmt) == 1)
			set_precision(flags, fmt);
		else if (*fmt == '*')
			set_precision_asterisk(flags, fmt, argptr);
	}
	parse_type(flags, fmt);
}

static void	init_flags(void *ptr, size_t size)
{
	ft_bzero(ptr, size);
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
