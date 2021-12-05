/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:51:32 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/29 03:02:37 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	printuint(unsigned int n, int ct)
{
	char		last_digit;

	if (n > 9)
	{
		ct = printint(n / 10, ct);
	}
	last_digit = n % 10 + '0';
	ct += write(1, &last_digit, 1);
	return (ct);
}
