/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:27:30 by tiacovel          #+#    #+#             */
/*   Updated: 2023/11/29 17:40:34 by tiacovel         ###   ########.fr       */
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

// END OF THE OUTILS *******************

char	*check_line(char *stach)
{
	int	size;

	size = 0;
	while (*stach != '\n')
	{
		if (*stach == 0)
			return (NULL);
		stach++;
		
	}
	return (size);
}

char	*get_next_line(int fd)
{
	static char	*stach;
	char		buffer[BUFFER_SIZE];
	char		*next_line;
	int			bytes_read;
	int			line_size;

	if (fd < 0)
		return (NULL);
	stach = malloc(sizeof(char)*0);
	if (!stach)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		stach = ft_strjoin(stach, buffer);
		next_line = check_line(buffer);
	}
	return (next_line);
}

#include <fcntl.h>
#include <stdio.h>
int main (void)
{
	int fd;
	char *line;
	char test[6] = "Hello";

	/* fd = open("test.txt", O_RDWR);
	if (fd == -1)
		printf("Error opening the file!!");
	line = get_next_line(fd);
	close(fd); */
	
	line = malloc(sizeof(char)*0);
	if (!line)
		return (0);
	line = ft_strjoin(line, test);
	printf("TEST: %s", line);
	/* int len = ft_strlen(line);
	printf("TEST: %d", len); */
	return (0);
}