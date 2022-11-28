# include "get_next_line.h"
# include <stdio.h>

int main()
{
    int fd;
    char *line = NULL;

    fd = open ("test.txt", O_RDONLY);
    //line = malloc(sizeof(*line));
    // if (!line)
    //     return (0);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        printf("%s|", line);
        free (line);
    }
    close (fd);
    //system("leaks a.out");
    return (0);
}