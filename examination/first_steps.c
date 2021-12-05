#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler (int num)
{
	write(STDOUT_FILENO, "\t\tNice try :DD\n", 16);
	static int i = 0;
	i++;
	if (i == 5)
	{
		write(1, "okay calm down you win\n", 24);
		exit(0);
	}
}

void handler2 (int num)
{
	write(STDOUT_FILENO, "\t\tBig Brains won't help you :O\n", 32);
}

int main()
{
	int i;
	i = 0;
	signal(SIGQUIT, handler2);
	while (1)
	{
		write(1, ">:D\n", 4);
		sleep(1);
		i++;
		signal(SIGINT, handler);
		if (i == 10)
			write(1, "still here? :P\n", 16);
		if (i == 15)
			write(1, "There is no escape\n", 20);
	}
	return (0);
}
