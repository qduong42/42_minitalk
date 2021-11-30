/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:09:44 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/30 02:27:14 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Program display PID, waits for signal and prints received string 
*/

#include <signal.h>
#include <unistd.h>
#include "printf/ft_printf.h"

void	binary_receiver(int sig)
{
	static int				i = 0;
	static unsigned char	c = 0;

	c = c | (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		ft_printf("%c", c);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	int	id;

	id = getpid(); /* gets - process id - (PID) */
	ft_printf("Server pid: %i\n", id); /* prints process id */
	signal(SIGUSR1, binary_receiver);
	signal(SIGUSR2, binary_receiver);
	while (1)
		pause(); // hypotheticaly holds from exit
	return (0);
}
