#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 4

char	*check_char(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (0);
}

size_t	ft_strlenne(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoinn(char *total_buff, char *tmp) // ajouter a la suite de ttbuf, tmp
{
	char	*str;
	size_t	i;
	size_t	total_size;
	size_t	tmp_size;

	i = 0;
	if (!total_buff)//la premiere fois il est vide
	{
		total_buff = malloc(sizeof(char) * 1);
		if (!total_buff)
			return (NULL);
	}
	total_size = ft_strlenne(total_buff);
	tmp_size = ft_strlenne(tmp);
	str = malloc(sizeof(char) *(total_size + tmp_size + 1));
	if (!str)
		return (NULL);
	while (i++ < total_size)
		str[i - 1] = total_buff[i - 1];
	i = 0;
	while (i++ < tmp_size)
		str[total_size + i - 1] = tmp[i - 1];
	str[total_size + i - 1] = '\0';
	free(total_buff);
	return (str);
}

char	*fd_read(int fd, char *total_buff)
{
	char	*tmp;
	int		chk;

	tmp = malloc(BUFFER_SIZE);
	if (!tmp)
		return (0);
	chk = 1;
	while (chk > 0 && !check_char(tmp, '\n'))
	{
		chk = read(fd, tmp, BUFFER_SIZE); // donne val de fd->chk et tmp dune size de B_S
		if (chk > 0) //si on ya tjrs des choses a lire
		{
			tmp [chk] = '\0';
			total_buff = ft_strjoinn(total_buff, tmp);
		}
	}
	free(tmp);
	if (chk == -1)
	{
		free(total_buff);
		return (0);
	}
	return (total_buff);
}

char	*ft_substrr(const char *total_buff, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;
	size_t	len_src;

	if (!total_buff)
		return (NULL);
	len_src = ft_strlenne(total_buff);
	if (len_src < start)
		start = len_src;
	if (len_src - start < len)
		len = len_src - start;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	count = 0;
	while (start + count < len_src && count < len)
	{
		str[count] = total_buff[start + count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

char	*take_line(char *total_buff)
{
	char	*rtrn_buff;
	size_t	size;

	size = 0;
	if (!total_buff)
		return(0);
	while (total_buff[size] != '\n' && total_buff[size] != '\0')
		size++;
	if (total_buff[size] == '\n')
		rtrn_buff = ft_substrr(total_buff, 0, size + 1);
	else
		rtrn_buff = ft_substrr(total_buff, 0, size);
	return (rtrn_buff);	
}
char	*cut_static(char *total_buff)
{
	size_t	indx;
	char	*new_total_buff;

	indx = 0;
	while (total_buff[indx] != '\n' && total_buff[indx] != '\0')
		indx++;
	if (total_buff[indx] == '\n' && total_buff[indx + 1] != '\0')
	{
		indx++;
		new_total_buff = ft_substrr(total_buff, indx,
				(ft_strlenne(total_buff) - indx));
		//printf("pour toi ;on bouef: %s !!et!! %s!\n", new_total_buff, total_buff);
	}
	else
		new_total_buff = NULL;
	free (total_buff);
	if (!new_total_buff)
		return (NULL);
	return (new_total_buff);
}

char	*get_next_line(int fd)
{
	static char *total_buff;
	char		*return_buff;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	if(!total_buff)
		total_buff = fd_read(fd, total_buff);//on remplie ttbuf de la premiere ligne
	return_buff = take_line(total_buff);//on peut pqs utiliser ttbuf car static essayer de juste remplir ttbuf
	if (!return_buff)
	{
		free(total_buff);
		return (0);
	}
	total_buff = cut_static(total_buff);
	return (return_buff);
}

int	main()
{
	int	fd;
	char	*line;

	fd = open("Myfile.txt", O_RDONLY);      //ouvre le fichier 'Myfile'
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		printf("%s", line);
		free(line);
	}
	return (0);
}
