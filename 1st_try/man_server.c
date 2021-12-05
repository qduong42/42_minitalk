/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 03:36:35 by qduong            #+#    #+#             */
/*   Updated: 2021/12/04 03:37:44 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

static void	binary_handler(int sig)
{
	static int	i = 0;
	static char	c = 0;

	c = c | (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	int	id;

	id = getpid();
	ft_printf("Server pid: %i\n", id);
	signal(SIGUSR1, binary_handler);
	signal(SIGUSR2, binary_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
