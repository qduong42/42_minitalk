/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 08:39:22 by qduong            #+#    #+#             */
/*   Updated: 2021/05/31 18:32:46 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ls1;
	unsigned char	*ls2;
	size_t			i;

	i = 0;
	ls1 = (unsigned char *) s1;
	ls2 = (unsigned char *) s2;
	if (!ls1 || !ls2)
		return (0);
	while (i < n)
	{
		if (ls1[i] != ls2[i])
			return (ls1[i] - ls2[i]);
		i++;
	}
	return (0);
}
