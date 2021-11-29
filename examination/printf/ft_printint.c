/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:52:10 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/22 22:36:00 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	printint(int n, int ct)
{
	char	last_digit;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ct += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ct = printint(n / 10, ct);
	}
	last_digit = n % 10 + '0';
	ct += write(1, &last_digit, 1);
	return (ct);
}
