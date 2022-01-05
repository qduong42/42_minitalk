/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 03:50:14 by qduong            #+#    #+#             */
/*   Updated: 2022/01/05 10:30:48 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

//byte counter counts characters received using 
//sigusr2 exits when sigusr1 (else) is sent

static void	byte_counter(int sig)
{
	static int	received_bytes = 0;

	if (sig == SIGUSR2)
		++received_bytes;
	else
	{
		ft_putnbr_fd(received_bytes, 1);
		write(1, "\n", 1);
		exit (0);
	}
}

//sends binary like in the mandatory, with exception of sending
//8 bytes of 0  in line 51-55 to trigger exit condition
//in server
static void	binary_converter(int server_pid, char *str)
{
	char	c;
	int		i;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(50);
		}
	}
	i = 8;
	while (i--)
	{
		kill(server_pid, SIGUSR1);
		usleep(50);
	}
}

//signal is used here instead of sigaction as no sigaction
//traits need to be used: signal mask/info/flags

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		ft_printf("Enter correct parameters in \
		form: ./client <PID> <string_to_send>\n");
		return (0);
	}
	server_pid = 0;
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0))
	{
		ft_printf("Invalid PID or string input.\
 Please start server in seperate terminal with\
: ./server\nUsage: ./client <Server_PID> <string_to_send>\n");
		return (0);
	}
	ft_printf("Sent characters: ");
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_printf("Received characters: ");
	signal(SIGUSR1, byte_counter);
	signal(SIGUSR2, byte_counter);
	binary_converter(server_pid, argv[2]);
	while (1)
		pause();
	return (0);
}
