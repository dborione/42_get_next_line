# include "get_next_line.h"
# include <stdio.h>

int main()
{
    int fd;
    int i = 2;
    fd = open ("test.txt", O_RDONLY);
    while (i > 0 && fd)
    {
        get_next_line(fd);
        i--;
    }
    close (fd);
    return (0);
}