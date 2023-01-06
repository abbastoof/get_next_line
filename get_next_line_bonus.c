/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:57:30 by atoof             #+#    #+#             */
/*   Updated: 2023/01/06 15:09:27 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* this function gets the remainder from
the last time get_next_line was called if it exists */
static char	*ft_new_line(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(s) - i + 1), sizeof(char *));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		str[j++] = s[i++];
	free(s);
	return (str);
}
/* this function takes the line that I will use this time */

static char	*ft_get_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		str[i++] = '\n';
	return (str);
}
/*In short, ssize_t is the same as size_t, but is a signed type
	- read ssize_t as “signed size_t”.
ssize_t is able to represent the number -1,
	which is returned by several system calls
and library functions as a way to indicate error. For example,
	the read and write system calls*/
/*
read -> ssize_t read(int fd, void *buf, size_t nbyte)
 read nbytes from a fd into a buffer starting with buf
 returns 0 if reached the end of the file or the number of bytes 
 read and -1 if there is an error
 buffer size -> how many characters will be read at a time in read
*/

static char	*ft_read_and_store(int fd, char *cached_str)
{
	char	*read_store;
	int		nbytes;
	char	*tmp;

	if (!cached_str)
		cached_str = ft_calloc(1, 1);
	read_store = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!read_store)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, read_store, BUFFER_SIZE);
		if (nbytes == -1)
			return (NULL);
		read_store[nbytes] = 0;
		tmp = ft_strjoin(cached_str, read_store);
		free(cached_str);
		cached_str = tmp;
		if (ft_strchr(cached_str, '\n'))
			break ;
	}
	free(read_store);
	return (cached_str);
}

char	*get_next_line(int fd)
{
	static char	*cached_str[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	cached_str[fd] = ft_read_and_store(fd, cached_str[fd]);
	if (!cached_str[fd])
		return (NULL);
	line = ft_get_line(cached_str[fd]);
	cached_str[fd] = ft_new_line(cached_str[fd]);
	return (line);
}