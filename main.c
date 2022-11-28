# include "get_next_line.h"
# include <stdio.h>

int main()
{
    int fd;
    char *line;
    int i = 10;

    fd = open ("test.txt", O_RDONLY);
    line = malloc(sizeof(*line));
    if (!line)
        return (0);
    while (i > 0)
    {
        printf("%s|", line);
        line = get_next_line(fd);
        free (line);
        i--;
    }
    close (fd);
    //system("leaks a.out");
    return (0);
}