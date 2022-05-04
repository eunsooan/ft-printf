/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:08:16 by ean               #+#    #+#             */
/*   Updated: 2022/02/05 14:36:01 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_NUMBERS_H
# define FT_PRINTF_NUMBERS_H
# include <stdarg.h>

int	print_ptr(va_list *ptr_ap);
int	print_decimal(va_list *ptr_ap);
int	print_unsigned_decimal(va_list *ptr_ap);
int	print_hexadecimal_lower(va_list *ptr_ap);
int	print_hexadecimal_upper(va_list *ptr_ap);

#endif
