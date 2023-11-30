# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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
    free (s1);
	return (new);
}

int main (void)
{
	static char *stach;
    char buffer[6] = "Hello";

    stach = malloc(5);
    if (!stach)
        return (0);
    stach[0] = '\0';

    stach = ft_strjoin(stach, buffer);
    printf("%s", stach);
    free(stach);

	return (0);
}