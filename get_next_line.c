#include "get_next_line.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:22:37 by atoof             #+#    #+#             */
/*   Updated: 2022/12/29 17:24:12 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_join(char *cached_str,char *read_store)
{
	char	str;
		str = ft_strjoin(cached_str, read_store);
		free(cached_str);
		return (str);
}

//this function gets the remainder from the last time get_next_line was called if it exists
char	*ft_new_line(char	*s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n') //while it does not reach EOF or new line, it continues advancing in the string
		i++;
	if (!s[i]) //if it doesn't exist
		free(s);
		return (NULL);
	str = (char *)malloc((ft_strlen(s) - i + 1) * sizeof(char)); ////allocate space for the size of s minus i 
	//to store what's left of this reading but that won't be used this time
	if (!str) //if it gives error
		return (NULL);
	i++; //include the \n
	j = 0;
	while (s[i]) //as long as you still have something in s
		str[j++] = s[i++];
	str[j] = '\0';
	free(s); // I clean it because I don't need it for anything anymore since I already kept it somewhere else (str)
	return (str);
}
////this function takes the line that I will use this time
char	*get_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char)); //allocate the line size up to the first \n or EOF
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*In short, ssize_t is the same as size_t, but is a signed type - read ssize_t as “signed size_t”.
ssize_t is able to represent the number -1, which is returned by several system calls
and library functions as a way to indicate error. For example, the read and write system calls*/
/*
read -> ssize_t read(int fd, void *buf, size_t nbyte)
 read nbytes from a fd into a buffer starting with buf
 returns 0 if reached the end of the file or the number of bytes 
 read and -1 if there is an error
 buffer size -> how many characters will be read at a time in read
*/

char	*ft_read_and_store(int fd, char *cached_str)
{
	char	*read_store;
	int		nbytes;

	read_store = malloc((BUFFER_SIZE + 1) * sizeof(char));// I set the necessary size for the buffer
	if (!read_store)
		return(NULL);
	nbytes = 1;
	while (!ft_strchr(cached_str, '\n') && nbytes != 0) //while I don't find \n and still have something to read
	{
		nbytes = read(fd, read_store, BUFFER_SIZE); // keep saving the read return
		if (nbytes == -1)
		{
			free(read_store);
			return (NULL);
		}
	read_store[nbytes] = '\0';
	cached_str = free_join(cached_str, read_store);// I merge what I just read with what I already had in the str
	}
	return (cached_str);
}

char *get_next_line(int fd)
{
    char *line; //a line
    static char *cached_str; //static because it remembers where it left off the last time the function is called

/*
if fd is negative and because it gave an error, and the buffer size less than or equal to 0 does not read anything,
This call will do all the usual error checking on the file descriptor, but not retrieve any data from it.
This is useful if you wish to for example determine if the file descriptor is still valid without blocking on it.
It will return -1 if an error occurs and 0 otherwise. Most of the errors listed in man 2 read can be queried in this way and will be returned in errno.
*/
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
    cached_str = ft_read_and_store(fd, cached_str);//I call the function that will read from the buffer and store the new str generated in cached_str
	if (!cached_str) //if you don't read anything 
		return (NULL);
	line = ft_get_line(cached_str); //the line I'm going to use now
	cached_str = ft_new_line(cached_str);//I keep what's left of this read
	return (line);
}
