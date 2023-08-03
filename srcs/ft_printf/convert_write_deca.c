/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_write_deca.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:42:16 by qduong            #+#    #+#             */
/*   Updated: 2021/11/23 16:43:06 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_deca(unsigned long n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i = convert_deca((n / 10));
		convert_deca((n % 10));
	}
	if (n < 10)
	{
		ft_putchar_fd(('0' + n), 1);
	}
	i++;
	return (i);
}

int	write_unsigned_dec(unsigned int u)
{
	int	i;

	i = 0;
	i = i + convert_deca(u);
	return (i);
}
