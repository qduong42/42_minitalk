/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:52:57 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/22 22:35:37 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	printstr(char *chr)
{
	int	ct;
	int	i;

	i = 0;
	ct = 0;
	if (!chr)
		return (write (1, "(null)", 6));
	while (chr[i])
	{
		ct += write (1, &chr[i], 1);
		i++;
	}
	return (ct);
}
