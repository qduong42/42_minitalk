/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:48:51 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/22 22:50:26 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	printaddr(unsigned long long int n, int ct)
{
	int		last_digit;

	if (ct == 0)
		ct += write(1, "0x", 2);
	if (n > 15)
	{
		ct = printaddr(n / 16, ct);
	}
	last_digit = n % 16;
	ct += write(1, &"0123456789abcdef"[last_digit], 1);
	return (ct);
}
