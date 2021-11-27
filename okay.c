#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler (int num)
{
	write(STDOUT_FILENO, "\t\tGood Bye :(\n", 15);
	exit(0);
}

int main()
{
	signal(SIGINT, handler);
	while (1)
	{
		write(1, ">:D\n", 4);
		sleep(1);
	}
	return (0);
}
