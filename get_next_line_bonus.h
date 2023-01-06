/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:59:33 by atoof             #+#    #+#             */
/*   Updated: 2023/01/06 15:19:38 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t len);

#endif