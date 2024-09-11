#include <stdlib.h>

// Helper function to check if a character is part of the charset (separator)
int is_separator(char c, char *charset)
{
    int i = 0;
    while (charset[i] != '\0')
    {
        if (c == charset[i])
            return (1);
        i++;
    }
    return (0);
}

// Helper function to count the number of words in the string
int count_words(char *str, char *charset)
{
    int i = 0;
    int count = 0;
    int in_word = 0;

    while (str[i] != '\0')
    {
        if (!is_separator(str[i], charset) && in_word == 0)
        {
            count++;
            in_word = 1;
        }
        else if (is_separator(str[i], charset))
            in_word = 0;
        i++;
    }
    return (count);
}

// Helper function to allocate memory and copy a word from str
char *ft_strndup(char *str, int start, int end)
{
    char *word = (char *)malloc(sizeof(char) * (end - start + 1));
    int i = 0;

    while (start < end)
        word[i++] = str[start++];
    word[i] = '\0';

    return word;
}

// Main function to split the string into an array of strings
char **ft_split(char *str, char *charset)
{
    int i = 0;
    int start = 0;
    int word_count = count_words(str, charset);
    char **result = (char **)malloc(sizeof(char *) * (word_count + 1));
    int word_index = 0;

    if (!result)
        return NULL;

    while (str[i] != '\0')
    {
        if (!is_separator(str[i], charset))
        {
            start = i;
            while (str[i] != '\0' && !is_separator(str[i], charset))
                i++;
            result[word_index++] = ft_strndup(str, start, i);
        }
        i++;
    }
    result[word_index] = NULL; // End the array with a NULL pointer
    return result;
}

// Example usage in main
#include <stdio.h>

int main(void)
{
    char *str = "Hello,world!This,is;split-test";
    char *charset = ",;!";
    char **split = ft_split(str, charset);

    int i = 0;
    while (split[i] != NULL)
    {
        printf("%s\n", split[i]);
        free(split[i]);
        i++;
    }
    free(split);

    return 0;
}
