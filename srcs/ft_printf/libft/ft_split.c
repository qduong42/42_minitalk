/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:25:38 by qduong            #+#    #+#             */
/*   Updated: 2021/06/12 00:21:43 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strcount(char const *s, char c)
{
	int		counter;
	int		j;
	int		string;

	counter = 0;
	j = 0;
	string = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c && string == 0)
		{
			string = 1;
			counter++;
		}
		else if (s[j] == c)
			string = 0;
		j++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		start;
	size_t	i[2];

	array = malloc((strcount(s, c) + 1) * sizeof(char *));
	i[0] = 0;
	i[1] = 0;
	start = -1;
	if (!array || !s)
		return (NULL);
	while (i[0] <= ft_strlen(s))
	{
		if (start < 0 && s[i[0]] != c)
			start = i[0];
		else if ((s[i[0]] == c || i[0] == ft_strlen(s)) && 0 <= start)
		{
			array[i[1]] = ft_substr(s, start, i[0] - start);
			start = -1;
			i[1]++;
		}
		i[0]++;
	}
	array[i[1]] = 0;
	return (array);
}

/*#include <stdio.h>
int main(void)
{
	int i = 0;
	char c = ' ';
	char s[100] = " aniuidna       cadad       bad ";
	char **r = ft_split(s, c);
	while (r[i])
	{
		printf("%d\t%d\t%p\t%s\n",i, (int)ft_strlen(r[i]), r[i], r[i]);
		i++;
	}
}*/
