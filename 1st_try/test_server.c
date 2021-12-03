/*
    Program display PID, waits for signal and prints received string 
*/

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

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

int    main(void)
{
    int    id;

    id = getpid(); /* gets - process id - (PID) */
    ft_printf("Server pid: %i\n", id); /* prints process id */
    signal(SIGUSR1, binary_handler);
	signal(SIGUSR2, binary_handler);
    while (1)    /* endless loop checks for incoming signal */
    {
        pause();
    }
    return (0);
}