/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:01:54 by qduong            #+#    #+#             */
/*   Updated: 2021/05/28 23:13:28 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function character to integer, check and skips first occurences of** 
**isspaces. Then check if first character is negative or positive, to**
**multiply with final result*/

int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	res;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		||str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	else
		is_neg = 1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}	
	return (res * is_neg);
}
