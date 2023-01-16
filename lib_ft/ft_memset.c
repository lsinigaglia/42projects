#include "libft.h"

void				*ft_memset(void *str, int c, size_t n)
{
    unsigned int i;
    char *p;

    i = 0;
    p = str;
    while (i < n)
    {
        p[i++] = c;
    }
    return str;
}