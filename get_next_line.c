/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:27:30 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/30 15:03:55 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// TO BE MOVED IN get_next_line_utils.c

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		newstr = malloc(sizeof(char));
		if (!newstr)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	newstr = malloc(sizeof(char) * len + 1);
	if (newstr == NULL)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		newstr[i] = s[start];
		i++;
		start++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *str, int c)
{
	while ((char)c != *str)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

// END OF THE OUTILS *******************

char *get_line(char *stach)
{
	char *line;
	int size = 0;
	while (stach[size] != '\n' && stach[size] != '\0')
		size++;
	line = ft_substr(stach, 0, size);
	return (line);
}

char *get_next_line(int fd)
{
	static char	*stach = NULL;
	char		buffer[BUFFER_SIZE];
	char		*next_line;
	int			bytes_read;

	if (fd < 0)
		return (NULL);
	if (!stach)
	{
		stach = malloc(BUFFER_SIZE + 1);
		if (!stach)
			return (NULL);
		stach[0] = '\0';
	}
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		buffer[bytes_read] = '\0';
		stach = ft_strjoin(stach, buffer);
		if (ft_strchr(stach, '\n') != NULL)
			break ;
	}
	if (bytes_read == 0 && stach[0] == '\0')
	{
		free(stach);
		stach = NULL;
		return (NULL);
	}
	next_line = get_line(stach);
	stach = ft_strchr(stach, '\n');
	stach++;
	return (next_line);
}


#include <fcntl.h>
#include <stdio.h>
int main (void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		printf("Error opening the file!!");

	for (size_t i = 0; i < 12; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	
	close(fd);

	return (0);
}
