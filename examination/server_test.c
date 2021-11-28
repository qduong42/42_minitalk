/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:09:44 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/28 23:50:34 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Program display PID, waits for signal and prints received string 
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/*
	Handler  
*/

void handler (int num)
{
	write(1, "Test\n", 5);
}

/*
	Main 
*/

int	main(void)
{
	pid_t	id;

	id = getpid(); /* gets - process id - (PID) */
	printf("Server pid: %d", id); /* prints process id */

	while (1)	/* endless loop checks for incoming signal */
	{
		sleep(10);
		// sigaction(SIGUSR1, &sa, NULL);
		// sigaction(SIGUSR2, &sa, NULL);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
