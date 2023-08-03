/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:54:37 by qduong            #+#    #+#             */
/*   Updated: 2021/06/01 13:19:57 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ldest;
	unsigned char	*lsrc;
	size_t			i;

	i = 0;
	ldest = (unsigned char *)dest;
	lsrc = (unsigned char *)src;
	if (!dest || !src)
		return (NULL);
	while (i < n)
	{
		ldest[i] = lsrc[i];
		if (lsrc[i] == (unsigned char) c)
		{
			return (ldest + i + 1);
		}	
		i++;
	}
	return (NULL);
}
