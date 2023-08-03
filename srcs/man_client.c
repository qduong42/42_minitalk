/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 03:26:11 by qduong            #+#    #+#             */
/*   Updated: 2021/12/04 03:33:58 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

static void	binary_converter(int server_pid, char *str)
{
	int		i;
	char	c;

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
			usleep(30);
		}
	}
}

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
	binary_converter(server_pid, argv[2]);
	return (0);
}
