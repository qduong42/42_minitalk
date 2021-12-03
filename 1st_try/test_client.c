/*
    takes server PID and sends received string to PID
*/

#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	binary_converter(int server_pid, char *str)
{
	int i;
	char c;
	while(*str)
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
	exit(0);
}

int    main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_printf("Enter correct parameters in form: ./client <PID> <string_to_send>\n");
        return(0);
    }
    int    server_pid;
    server_pid = 0;
    server_pid = ft_atoi(argv[1]);
	binary_converter(server_pid, argv[2]);
    while (1)
        pause();
    return (0);
}