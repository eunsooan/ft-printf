/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:18:51 by ean               #+#    #+#             */
/*   Updated: 2022/02/08 08:30:05 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_printf_letters.h"
#include "ft_printf_numbers.h"

static int	bad_format_string(const char *str);
static int	is_valid_conversion_specifier(const char c);
static int	print_till_percent_or_null(const char **str);
static void	func_tab_init(int (**tab)(va_list *));

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			(*func_tab[128])(va_list *);
	const char	*curr;
	int			chars_printed;

	if (bad_format_string(format))
		return (-1);
	va_start(ap, format);
	func_tab_init(func_tab);
	curr = format;
	chars_printed = 0;
	while (*curr)
	{
		if (*curr == '%')
		{
			chars_printed += (*func_tab[(int)*(curr + 1)])(&ap);
			curr += 2;
		}
		else
			chars_printed += print_till_percent_or_null(&curr);
	}
	va_end(ap);
	return (chars_printed);
}

static int	bad_format_string(const char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			if (!is_valid_conversion_specifier(*str))
				return (1);
		}
		++str;
	}
	return (0);
}

static int	is_valid_conversion_specifier(const char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	print_till_percent_or_null(const char **str)
{
	const char	*start;
	int			chars_printed;

	start = *str;
	while (**str && **str != '%')
		++(*str);
	chars_printed = write(1, start, *str - start);
	return (chars_printed);
}

static void	func_tab_init(int (**tab)(va_list *))
{
	tab['c'] = print_char;
	tab['s'] = print_str;
	tab['p'] = print_ptr;
	tab['d'] = print_decimal;
	tab['i'] = print_decimal;
	tab['u'] = print_unsigned_decimal;
	tab['x'] = print_hexadecimal_lower;
	tab['X'] = print_hexadecimal_upper;
	tab['%'] = print_percent;
}
