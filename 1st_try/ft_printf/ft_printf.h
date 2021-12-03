/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:58:38 by qduong            #+#    #+#             */
/*   Updated: 2021/11/23 17:05:01 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	convert_deca(unsigned long n);
int	write_unsigned_dec(unsigned int u);
int	convert_hexa_lowercase(unsigned long n);
int	convert_hexa_uppercase(unsigned long n);
int	write_lower_hexa(unsigned int x);
int	write_upper_hexa(unsigned int y);
int	conversion(va_list args, char format);
int	write_character(char c);
int	write_string(char *str);
int	write_pointer(unsigned long ptr);
int	write_double(int d);

#endif