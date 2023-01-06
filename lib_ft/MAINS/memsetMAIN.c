#include "libft.h"
#include <stdio.h>

void				*ft_memset(void *str, int c, size_t n)
{
    int i;
    char *p;

    i = 0;
    p = str;
    while (i < n)
    {
        p[i++] = c;
    }
    return str;
}

int main()
{
    char    stringa[] = "ciao_zio_frank";
    ft_memset (stringa+5, '#', 3*sizeof(char));
    printf ("%s", stringa);
}