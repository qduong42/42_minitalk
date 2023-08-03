/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:53:37 by qduong            #+#    #+#             */
/*   Updated: 2021/11/23 20:02:47 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	digits(long x)
{
	size_t	i;

	i = 0;
	if (x == 0)
		i = 1;
	while (x > 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

static	char	*convert(long n, char *str, int numdigits, int neg)
{
	str[numdigits + neg] = '\0';
	while (numdigits > 0)
	{
		if (neg)
		{
			str[0] = '-';
		}
		str[numdigits + neg - 1] = n % 10 + '0';
		n = n / 10;
		numdigits--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*istr;
	size_t	numdigits;
	long	x;
	int		neg;

	x = (long)n;
	if (x < 0)
	{
		x = x * -1;
		neg = 1;
	}
	else
		neg = 0;
	numdigits = digits(x);
	istr = malloc(sizeof(char) * numdigits + 1 + neg);
	if (!istr)
		return (NULL);
	convert(x, istr, numdigits, neg);
	return (istr);
}
