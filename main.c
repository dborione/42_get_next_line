#include "get_next_line_bonus.h"
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;
    int     i;

    line = NULL;
    i = 10;
    fd = open("test2.txt", O_RDONLY);
    while (i > 0)
    {
        line = get_next_line_bonus(fd);
        printf("%s|", line);
        free(line);
        i--;
    }
    close (fd);
    system("leaks a.out");
    return (0);
}