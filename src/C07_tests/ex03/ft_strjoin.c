#include <stdlib.h>

// Function to calculate the length of a string
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

// Function to calculate the combined size of all strings including the separators
int	ft_combsize(int size, char **strs, char *sep)
{
	int	i;
	int	combsize;

	i = 0;
	combsize = 0;
	// Sum up the length of each string in the array
	while (i < size)
	{
		combsize += ft_strlen(strs[i]);
		i++;
	}
	// Add space for the separators (if size > 1)
	if (size > 1)
		combsize += ft_strlen(sep) * (size - 1);
	return (combsize);
}

// Function to concatenate src string into the destination string
char	*ft_strcat(char *dest, char *src)
{
	int	idest = ft_strlen(dest); // Start from the end of the current dest string
	int	isrc = 0;

	// Copy src to dest starting from the null terminator of dest
	while (src[isrc] != '\0')
	{
		dest[idest + isrc] = src[isrc];
		isrc++;
	}
	dest[idest + isrc] = '\0'; // Ensure the resulting string is null-terminated
	return (dest);
}

// Function to join all strings from strs array, separated by sep
char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		combsize;
	char	*dest;
	int		i;

	// If size == 0, return an empty string
	if (size == 0)
	{
		dest = malloc(1);
		if (dest)
			dest[0] = '\0'; // Return an empty string
		return (dest);
	}

	// Calculate the total size required for the final concatenated string
	combsize = ft_combsize(size, strs, sep);
	dest = malloc(sizeof(char) * (combsize + 1)); // +1 for the null terminator
	if (dest == NULL)
		return (NULL);

	dest[0] = '\0'; // Initialize the destination string as empty
	i = 0;
	// Concatenate all strings and add separator between them
	while (i < size)
	{
		ft_strcat(dest, strs[i]); // Add current string
		if (i < size - 1) // Add separator after each string except the last one
			ft_strcat(dest, sep);
		i++;
	}
	return (dest); // Return the final concatenated string
}

#include <stdio.h>

int main(void)
{
    char *strs[] = {"Hello", "world", "from", "C"};
    char *sep = " ";
    char *result = ft_strjoin(4, strs, sep);

    if (result != NULL)
    {
        printf("%s\n", result); // Output: "Hello world from C"
        free(result); // Free allocated memory after use
    }

    return 0;
}
