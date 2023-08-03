/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:50:34 by qduong            #+#    #+#             */
/*   Updated: 2021/11/23 16:53:52 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_character(char c)
{
	write(1, &c, 1);
	return (1);
}

int	write_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}

int	write_pointer(unsigned long ptr)
{
	int	i;

	i = 2;
	write(1, "0x", 2);
	if (ptr == 0)
	{
		write(1, "0", 1);
		i++;
	}
	else
		i = i + convert_hexa_lowercase(ptr);
	return (i);
}

int	write_double(int d)
{
	char	*str;
	int		n;

	n = 0;
	str = ft_itoa(d);
	ft_putstr_fd(str, 1);
	n = ft_strlen(str);
	free (str);
	return (n);
}

int	ft_printf(const char *format, ...)
{
	int			is_variable;
	int			bytes_written;
	va_list		args;

	va_start (args, format);
	is_variable = 0;
	bytes_written = 0;
	while (*format)
	{
		if (is_variable)
		{
			bytes_written += conversion(args, *format);
			is_variable = 0;
		}
		else if (*format != '%')
		{
			write(1, format, 1);
			bytes_written++;
		}
		else
			is_variable = 1;
		format++;
	}
	va_end (args);
	return (bytes_written);
}
