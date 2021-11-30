/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:09:38 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/30 02:06:44 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	binary_trigger(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i)
		{
			i--;
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int argv, char **args)
{
	int	i;
	int	pid;

	pid = ft_atoi(args[1]);
	binary_trigger(pid, args[2]);
	usleep(100);
	return (0);
}
