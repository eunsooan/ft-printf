/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_letters.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:01:22 by ean               #+#    #+#             */
/*   Updated: 2022/02/05 14:35:43 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LETTERS_H
# define FT_PRINTF_LETTERS_H
# include <stdarg.h>

int	print_char(va_list *ptr_ap);
int	print_str(va_list *ptr_ap);
int	print_percent(va_list *ptr_ap);

#endif
