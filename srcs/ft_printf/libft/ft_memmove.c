/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:53:06 by qduong            #+#    #+#             */
/*   Updated: 2021/06/05 19:31:13 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*size_t buffersrc;
**buffersrc = (sizeof(src)-1)
**if (n > ft_strlen(dest) || n > ft_strlen)
**n = ft_strlen(dest); */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (d > s)
	{
		while (n)
		{
			n = n - 1;
			d[n] = s[n];
		}
	}
	else
	{
		while (n)
		{
			d[i] = s[i];
			i++;
			n--;
		}
	}
	return (dest);
}
