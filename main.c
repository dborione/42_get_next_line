# include "get_next_line.h"

int main()
{
    int fd;

    fd = open ("test.txt", O_RDONLY);
    get_next_line(fd);
    close (fd);
    return (0);
}