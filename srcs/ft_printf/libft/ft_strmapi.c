/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:54:36 by qduong            #+#    #+#             */
/*   Updated: 2021/06/02 12:22:35 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*pstr;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	pstr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!pstr)
		return (NULL);
	while (s[i])
	{
		pstr[i] = (*f)(i, s[i]);
		i++;
	}
	pstr[i] = '\0';
	return (pstr);
}
