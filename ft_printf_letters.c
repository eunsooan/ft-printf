/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_letters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:22:35 by ean               #+#    #+#             */
/*   Updated: 2022/02/06 15:41:20 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_letters.h"

int	print_char(va_list *ptr_ap)
{
	unsigned char	c;
	int				chars_printed;

	c = va_arg(*ptr_ap, int);
	chars_printed = write(1, &c, 1);
	return (chars_printed);
}

int	print_str(va_list *ptr_ap)
{
	char	*str;
	int		len;
	int		chars_printed;

	str = va_arg(*ptr_ap, char *);
	if (!str)
		chars_printed = write(1, "(null)", 6);
	else
	{
		len = 0;
		while (str[len])
			++len;
		chars_printed = write(1, str, len);
	}
	return (chars_printed);
}

int	print_percent(va_list *ptr_ap)
{
	int	chars_printed;

	(void)ptr_ap;
	chars_printed = write(1, "%", 1);
	return (chars_printed);
}
