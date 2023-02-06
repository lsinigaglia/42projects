#include "get_next_line.h"

int main ()
{
	char	*s;
	int		i;
	int		index;

	index = 0;
	i = open("hello.c", O_RDONLY);
	while (++index < 15)
	{
		s = get_next_line(i);
		if (s)
			printf("%s", s);
		else
			printf("(null)\n");
	}
}
//3456783534534646
