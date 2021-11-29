/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:09:44 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/29 23:45:14 by emomkus          ###   ########.fr       */
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

// void handler(int sig, siginfo_t *info, void *context)
// {
// 	write(1, "Test\n", 5);
// }

void handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("0");
	else
		ft_printf("1");
}

/*
	Main 
*/

int	main(void)
{
	int	id;
	// struct	sigaction receiver;
	
	// receiver.sa_sigaction = handler;
	// receiver.sa_flags = SA_SIGINFO;
	id = getpid(); /* gets - process id - (PID) */
	ft_printf("TS Server pid: %i\n", id); /* prints process id */

		/* endless loop checks for incoming signal */
		// sigaction(SIGUSR1, &sa, NULL);
		//sigaction(SIGUSR2, &receiver, NULL);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
