# include "get_next_line.h"
# include <stdio.h>

int main()
{
    int fd;
    char *line = NULL;
    int i = 10;

    fd = open("test2.txt", O_RDONLY);
    //line = malloc(sizeof(*line));
    // if (!line)
    //     return (0);
    while (i > 0)
    {
        line = get_next_line(fd);
        printf("%s|", line);
        free (line);
        i--;
    }
    //close (fd);
    system("leaks a.out");
    return (0);
}