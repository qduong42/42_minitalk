/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:48:52 by qduong            #+#    #+#             */
/*   Updated: 2021/11/23 17:03:05 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(va_list args, char format)
{
	if (format == 'c')
		return (write_character(va_arg(args, int)));
	if (format == 's')
		return (write_string(va_arg(args, char *)));
	if (format == 'p')
		return (write_pointer(va_arg(args, unsigned long)));
	if (format == 'd' || format == 'i')
		return (write_double(va_arg(args, int)));
	if (format == 'x')
		return (write_lower_hexa(va_arg(args, unsigned int)));
	if (format == 'X')
		return (write_upper_hexa(va_arg(args, unsigned int)));
	if (format == 'u')
		return (write_unsigned_dec(va_arg(args, unsigned int)));
	if (format == '%')
	{
		write(1, "\%", 1);
		return (1);
	}
	return (0);
}
