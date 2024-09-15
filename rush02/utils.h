#ifndef UTILS_H
#define UTILS_H

void ft_putstr(char *str);
void ft_putchar(char c);
int ft_strlen(char *str);
char *ft_strcpy(char *dest, char *src);
char *ft_strcat(char *dest, char *src);
char *ft_strdup(char *src);
char *ft_strndup(char *src, int n);
char *ft_trim(char *str);
char **ft_split_lines(char *str, int *line_count);

#endif
