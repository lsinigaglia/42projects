#include "get_next_line.h"
int main ()
{
    int i;
    char buf[1000];

    i = open("MAIN.c", O_RDONLY);
    printf("%s", get_the_line(i, buf));
   
}