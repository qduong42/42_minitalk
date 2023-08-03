/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:55:04 by qduong            #+#    #+#             */
/*   Updated: 2021/11/23 20:01:53 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ldest;
	char	*lsrc;
	size_t	i;

	lsrc = (char *) src;
	ldest = (char *) dest;
	i = 0;
	while (i < n)
	{
		ldest[i] = lsrc[i];
		i++;
	}
	return (dest);
}
