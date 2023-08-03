/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:54:39 by qduong            #+#    #+#             */
/*   Updated: 2021/05/31 13:05:11 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pch;
	int		lstr;

	pch = (char *) s;
	lstr = (ft_strlen(s));
	while (lstr >= 0)
	{
		if (pch[lstr] == (unsigned char) c)
		{
			return (pch + lstr);
		}
		lstr--;
	}
	return (NULL);
}
