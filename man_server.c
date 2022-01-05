/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 03:36:35 by qduong            #+#    #+#             */
/*   Updated: 2022/01/04 16:25:15 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

/* Project sends signals defined by user SIGUSR 1 and SIGUSR 2 to represent
binary representations of the characters that should be sent
This is done by using bitwise operators to dismantle characters and send 
character representation bit by bit. This project was written to be as clean
as possible, carefully seperating the project into mandatory parts, and
bonus parts, depending on exactly what function is needed.
*/

//handles the binary to receive signals from client
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
