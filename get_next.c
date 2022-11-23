#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 32
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
//get next line doit lire ligne par ligne
/*char    *check_char(char *str, int c)
{
    if (!str)
        return (0);
    while (*str != '\0')
    {
        if ((char)c)
            return ((char *)str);
    }
    return (str);
}*/


/*
    //get the length of the destination string
    int len = len - start;

    //allocate (len + 1) chars for destination (+1 for extra null character)
    char *dest = malloc(sizeof(char) * (len + 1));

    
    //extracts characters between m'th and n'th index from source string
    //and copy them into the destination string
    
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
 
    //null-terminate the destination string
    *dest = '\0';
 
    //return the destination string
    return dest - len;
}
*/
ssize_t ft_strlen(const char *str)
{
    ssize_t i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
//cree un malloc avec juste la size de la ligne a afficher
char    *ft_substr(char const *str, unsigned int start, size_t len)
{
    char    *ptr;
    ssize_t i;
    ssize_t j;

    if (!str)
        return (0);
    j = ft_strlen(str);
    if (start > j)
        start = j;//strdup
    if (len + start > j)
		len = j - start;
	ptr = malloc(sizeof(char) * len);
    if (!ptr)
        return (0);
    j = 0;
    i = start;
	while (len != 0)
	{
		ptr[j++] = str[i++];
        len--;
	}
    ptr[j] = '\0';
	printf("ptr :%s\n", ptr);
    return (ptr);
}


//recuperer la ligne 
char    *line(char *total_buff)
{
    char *result;
    size_t i;

    i = 0;
    if (!total_buff)
        return (0);
    while (total_buff[i] != '\n' && total_buff[i] != '\0')
        i++;
    if (total_buff[i] == '\n')
        result = ft_substr(total_buff, 0, i + 1);
    else
        result = ft_substr(total_buff, 0, i);
	printf("result :%s\n", result);
    return (result);  
}
// implementer un chaine a une autre (je crois on cree de la place pour use substr)
char	*ft_strjoin(char *total_buff, char *tmp)
{
	char	*ptr;
	size_t	i;
	size_t	k;

    k = ft_strlen(total_buff) + ft_strlen(tmp);
    ptr = malloc(sizeof(char) * (k + 1))
    if (!ptr || (total_buff == 0 && tmp == 0))
        return (0);
	i = 0;
    k = 0;
    while(total_buff[i])
        ptr[k++] = total_buff[i++];
    i=0
    while (tmp[i])
        ptr[k++] = tmp[i++];
    ptr[k] = '\0';
	free(total_buff);
	return (str);
}
//on read et on ajoute a total_buff, tmp qui est le nb de charactere read. 
char	*fd_read(int fd, char *total_buff)
{
	char	*tmp;
	int		chk;

	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	chk = 1;
	while (chk > 0 && *tmp)
	{
		chk = read(fd, tmp, BUFFER_SIZE);
		if (chk > 0)
		{	
			tmp[chk] = '\0';
			total_buff = ft_strjoin(total_buff, tmp);
		}
	}
	free(tmp);
	if (chk == -1)
	{
		free(total_buff);
		return (NULL);
	}
	return (total_buff);
}


char    *get_next_line(int fd)
{
    static char *buff; // static pour garder en memoire a quelle ligne nous sommes! (la fonction lie ligne par ligne)
    char    *rslt;

    buff = fd_read(fd, buff);
    
    rslt = line(buff);
	printf("rslt :%s\n", rslt);
    if (!rslt)
    {
        free(buff);
        return (0);
    }
    return (rslt);
} 

/*
char	*ft_malloc(size_t size)
{
	char	*str;

	str = malloc(sizeof(char) * (size) + 1);
	if (!str)
		return (NULL);
	//str[size + 1] = '\0';
	return (str);
}*/

/*
char *test(int fd)
{
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
    -------------------------------------------------
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
}*/

int main()
{
	int	fd;
	char	*line;

	fd = open("myfile.txt", O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	printf("result :\n%s", line);
	free(line);
	return (0);
}
