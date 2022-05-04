/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:34:18 by ean               #+#    #+#             */
/*   Updated: 2022/02/06 16:11:43 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_numbers.h"
#include "print_base.h"

int	print_decimal(va_list *ptr_ap)
{
	long	num;
	int		chars_printed;

	num = (long)va_arg(*ptr_ap, int);
	chars_printed = 0;
	if (num < 0)
	{
		num = -num;
		chars_printed += write(1, "-", 1);
	}
	chars_printed += print_base(num, 10, "0123456789");
	return (chars_printed);
}

int	print_unsigned_decimal(va_list *ptr_ap)
{
	unsigned long	num;
	int				chars_printed;

	num = (unsigned int)va_arg(*ptr_ap, int);
	chars_printed = print_base(num, 10, "0123456789");
	return (chars_printed);
}

int	print_hexadecimal_lower(va_list *ptr_ap)
{
	unsigned long	num;
	int				chars_printed;

	num = (unsigned int)va_arg(*ptr_ap, int);
	chars_printed = print_base(num, 16, "0123456789abcdef");
	return (chars_printed);
}

int	print_hexadecimal_upper(va_list *ptr_ap)
{
	unsigned long	num;
	int				chars_printed;

	num = (unsigned int)va_arg(*ptr_ap, int);
	chars_printed = print_base(num, 16, "0123456789ABCDEF");
	return (chars_printed);
}

int	print_ptr(va_list *ptr_ap)
{
	unsigned long	num;
	int				chars_printed;

	num = (unsigned long)va_arg(*ptr_ap, void *);
	chars_printed = write(1, "0x", 2);
	chars_printed += print_base(num, 16, "0123456789abcdef");
	return (chars_printed);
}
