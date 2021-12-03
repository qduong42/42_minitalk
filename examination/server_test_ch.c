#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

// static void	action(int sig, siginfo_t *info, void *context)
// {
// 	static int				i = 0;
// 	static pid_t			client_pid = 0;
// 	static unsigned char	c = 0;

// 	(void)context;
// 	if (!client_pid)
// 		client_pid = info->si_pid;
// 	c = c | (sig == SIGUSR2);
// 	if (++i == 8)
// 	{
// 		i = 0;
// 		if (!c)
// 		{
// 			kill(client_pid, SIGUSR2);
// 			client_pid = 0;
// 			return ;
// 		}
// 		ft_printf("%c", c);
// 		c = 0;
// 		kill(client_pid, SIGUSR1);
// 	}
// 	else
// 		c <<= 1;
// }

static void	action(int sig)
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
	// struct sigaction	s_sigaction;
	int					id;

	id = getpid(); /* gets - process id - (PID) */
	ft_printf("TS Server pid: %i\n", id); /* prints process id */
	// s_sigaction.sa_sigaction = action;
	// s_sigaction.sa_flags = SA_SIGINFO;
	// sigaction(SIGUSR1, &s_sigaction, 0);
	// sigaction(SIGUSR2, &s_sigaction, 0);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);

	while (1)
		pause();
	return (0);
}
