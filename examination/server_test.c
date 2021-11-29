/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:09:44 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/29 06:10:39 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Program display PID, waits for signal and prints received string 
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "printf/ft_printf.h"
#include <execinfo.h>

/*
	Handler  
*/

void handler(int sig, siginfo_t *info, void *context)
{
	write(1, "Test\n", 5);
}

/*
	Main 
*/

int	main(void)
{
	int	id;
	struct	sigaction receiver;
	
	receiver.sa_sigaction = handler;
	receiver.sa_flags = SA_SIGINFO;
	id = getpid(); /* gets - process id - (PID) */
	ft_printf("Server pid: %i\n", id); /* prints process id */

	while (1)	/* endless loop checks for incoming signal */
	{
		sleep(100);
		// sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &receiver, NULL);
		// signal(SIGUSR2, handler(SIGUSR2));
	}
	return (0);
}
