/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarco <smarco@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:30:30 by smarco            #+#    #+#             */
/*   Updated: 2023/01/31 19:39:25 by smarco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*my_malloc(size_t nbytes, size_t size);
char	*ft_substr(const char *total_buff, unsigned int start, size_t len);
char	*ft_strjoin(char *total_buff, char *tmp);
char	*fd_read(int fd, char *total_buff);
char	*take_line(char *total_buff);
char	*cut_static(char *total_buff);
char	*get_next_line(int fd);
char	*check_char(const char *str, int c);
size_t	ft_strlen(const char *str);

#endif
