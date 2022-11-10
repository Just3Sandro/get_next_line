#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
char    *get_next_line(int fd)
{
    int BUFFER_SIZE = 10;
    char    *str;
    char    *buf;
    int j = 0;
    int k = 0;

    str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    str[BUFFER_SIZE--] = '\0';
    while (BUFFER_SIZE != 0)
    {
        read(fd, buf, 1);
        printf("buf > %c\n", buf[k]);
        str[j] = buf[k];
        j++;
        k++;
        BUFFER_SIZE--;
    }
    return (str);
}
*/


char *test(fd)
{
    ssize_t BUFFER_SIZE = 52;
    char	buf[BUFFER_SIZE];
    ssize_t i;
    ssize_t k;
    ssize_t l;
    ssize_t y = 0;
    
    i = BUFFER_SIZE;
    l = BUFFER_SIZE;
    while (i != 0)
    {
        k = 0;
        
        read(fd, buf, BUFFER_SIZE);
        while (l != 0)
        {
            //printf("buf > %c\n", buf[k]);
            y++;
            l--;
            k++;
        }
        i--;
    }
   // printf("malloc > %li\n", y);
    /*-------------------------------------------------*/
   //remplire le str;
    char *str;
    i = 7;
    i = BUFFER_SIZE;
    l = BUFFER_SIZE;
    
    str = malloc(sizeof(char) * (y + 1));
    str[y + 1] = '\0';
    BUFFER_SIZE = 0;
    k = 0;
    while (i != 0)
    {
        read (fd, buf, 1);
            str[BUFFER_SIZE] = buf[k];
            BUFFER_SIZE++;
        k++;
        i--;
    }
    return (str);
    free(str);
}

int main()
{
	int	fd;
	char	*line;

	fd = open("myfile.txt", O_RDONLY);
		line = test(fd);
		if (line == NULL)
			printf("NULL");
		printf("result :\n%s", line);
		free(line);
	return (0);
}