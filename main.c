# include "get_next_line.h"
# include <stdio.h>

int main()
{
    int fd;
    int i = 10;
    fd = open ("test2.txt", O_RDONLY);
    while (i > 0 && fd)
    {
        printf("%s|", get_next_line(fd));
        i--;
    }
    close (fd);
    return (0);
}