# include "get_next_line.h"
# include <stdio.h>

int main()
{
    int fd;
    char *line;
    int i = 10;
    fd = open ("test.txt", O_RDONLY);
    while (i > 0 && fd)
    {
        //printf("%s|", get_next_line(fd));
        line = get_next_line(fd);
        printf("%s|", line);
        i--;
        free (line);
    }
    close (fd);
    //system("leaks a.out");
    return (0);
}