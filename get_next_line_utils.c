/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:35 by atoof             #+#    #+#             */
/*   Updated: 2023/01/05 15:49:51 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
    char    *str;
    
    str = (char *)s;
    while (*str != c)
    {
        if (*str == '\0')
            return (NULL);
        str++;
    }
    return (str);
}

size_t    ft_strlen(char *c)
{
    size_t i;
    
    if (!c)
        return (0);
    i = 0;
    while (c[i])
        i++;
    return (i);
}

char    *ft_strjoin(const char  *s1, const char *s2)
{
    int 	i;
    int		len1;
    int		len2;
	char	*str;
	
	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (!str)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}
