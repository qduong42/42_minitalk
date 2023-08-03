#include <stdio.h>
#include <stdarg.h>

void print_ints(int num, ...)
{
	va_list args;
	va_start(args, num);
	int i;
	i = 0;
	while (i < num)
	{
		int value = va_arg(args,int);
		printf("%d: %d\n", i, value);
		i++;
	}
	va_end(args);
}

int main(void)
{
	print_ints(4,5,6,78,8);
}

int shit_printf(const char *format, ...)
{
	va_list args;
	int done;
	char *substring = strstr(format, "Jacob");
	if (substring != format) return 0;

	va_start (args, format);
	done = vfprintf (stdout, format, args);
	va_end (args);

	return done;
}