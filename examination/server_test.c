/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:09:44 by emomkus           #+#    #+#             */
/*   Updated: 2021/11/27 18:10:01 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/*
	Display PID, waits for signal and prints received string 
*/

int	main(void)
{
	pid_t	id;
	
	id = getpid(); /* gets - process id - (PID) */
	printf("Server pid: %d", id); /* prints process id */

	while (1)	/* endless loop checks for incoming signal */
	{
		sleep(1);
		signal(SIGINT, handler);
	}
	return (0);
}
