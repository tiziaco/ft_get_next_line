/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:27:30 by tiacovel          #+#    #+#             */
/*   Updated: 2023/12/01 18:30:50 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
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

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size * nitems)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
} */

char	*fill_stach(int fd, char *stach)
{
	char	*buffer;
	char	*tmp;
	int		bytes_read;

	if (!stach)
		stach = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stach, buffer);
		free(stach);
		stach = tmp;
		if (ft_strchr(stach, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (stach);
}

char	*get_tail(char *stach)
{
	char	*next_stach;
	int		i;
	int		j;

	i = 0;
	while (stach[i] && stach[i] != '\n')
		i++;
	if (!stach[i])
	{
		free(stach);
		return (NULL);
	}
	next_stach = ft_calloc(ft_strlen(stach) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (stach[i])
		next_stach[j++] = stach[i++];
	free(stach);
	return (next_stach);
}

char	*fill_line(char *stach)
{
	char	*line;
	int		i;

	i = 0;
	if (!stach[i])
		return (NULL);
	while (stach[i] && stach[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stach[i] && stach[i] != '\n')
	{
		line[i] = stach[i];
		i++;
	}
	if (stach[i] && stach[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stach;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stach = fill_stach(fd, stach);
	if (!stach)
		return (NULL);
	next_line = fill_line(stach);
	stach = get_tail(stach);
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

	for (size_t i = 0; i < 14; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	
	close(fd);

	return (0);
}
