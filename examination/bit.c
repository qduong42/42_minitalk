#include <stdio.h>
#include <unistd.h>

int	binary(char *str)
{
	int	i;
	char c;

	while (*str)
	{
		i = 0;
		c = *str++;
		while (i < 8)
		{
			printf("bit: %i: ", i);
			if (c >> i & 1)
				printf(" 1 ");
			else
				printf(" 0 ");
			i++;
		}
		printf("end of byte \n");
	}

	return 0;
}

int	main(void)
{
	int	i;
	char c = 0;
	char *str = "a";

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if ((c >> i) & 1)
				binary(&c);
			else
				binary(&c);
		}
	}
	// while (i--)
	// {
	// 	printf("0");
	// }
	return (0);
}