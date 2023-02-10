#include "get_next_line.h"

int main ()
{
	char	*s;
	int		i;
	int		index;

	index = -1;
	i = open("hello", O_RDONLY);
	while (++index < 1)
	{
		s = get_next_line(i);
		if (s)
		{
			printf("%s", s);
			//write(1, "!\n", 2);
		}
		else
			write(1, ")\n", 2);
	}
	close (i);
}
//3456783534534646d
