#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *src)
{
    int l;

    l = 0;
    while (src[l])
    {
        l++;
    }
    return (l);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		length;

    if (src == NULL)
		return (NULL);

	i = 0;
	length = ft_strlen(src) + 1;
	dest = malloc(sizeof(char) * length);
	if (dest == NULL)
		return (dest);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main(void)
{
    char *s1 = "Hello";
    printf("Before: %s\n", s1);

    char *s2 = ft_strdup(s1);
    if (s2) // Check if strdup was successful
    {
        printf("After: %s\n", s2);
        free(s2); // Free the allocated memory after use
    }
    else
    {
        printf("Memory allocation failed\n");
    }

    return 0;
}