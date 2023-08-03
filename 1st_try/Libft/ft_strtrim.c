/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:39:40 by qduong            #+#    #+#             */
/*   Updated: 2021/06/11 23:28:27 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	tlen;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
	{
		s1++;
	}
	tlen = ft_strlen(s1);
	while (ft_strchr(set, s1[tlen - 1]) && *s1)
		tlen--;
	trim = ft_substr(s1, 0, tlen);
	return (trim);
}
