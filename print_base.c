/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:09:29 by ean               #+#    #+#             */
/*   Updated: 2022/02/06 16:09:52 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print_base.h"
#define MAX_SIZE 20

static void	ft_strrev(char *str);

int	print_base(unsigned long num, int base, char *radix)
{
	char	digit_arr[MAX_SIZE];
	int		len;
	int		chars_printed;

	len = 0;
	digit_arr[len++] = radix[num % base];
	num /= base;
	while (num)
	{
		digit_arr[len++] = radix[num % base];
		num /= base;
	}
	digit_arr[len] = '\0';
	ft_strrev(digit_arr);
	chars_printed = write(1, digit_arr, len);
	return (chars_printed);
}

static void	ft_strrev(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = 0;
	while (str[len])
		++len;
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		++i;
	}
}
