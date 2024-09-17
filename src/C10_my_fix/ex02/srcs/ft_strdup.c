#include "../includes/ft.h"

char *ft_strdup(char *src)
{
	int	len;
	char	*dest;
	char	*orig;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	orig = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (orig);
}