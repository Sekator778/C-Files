#ifndef UTILS_H
# define UTILS_H

int     ft_strlen(char *str);
int     ft_strcmp(char *s1, char *s2);
void    ft_putstr(char *str);
void    ft_putchar(char c);
void    ft_putendl(char *str);
char    *ft_strdup(char *src);
char    *ft_strndup(char *src, int n);
char    *ft_strncpy(char *dest, char *src, int n);
char    *ft_trim(char *str);
int     ft_is_valid_number(char *str);
int     ft_isspace(char c);
int     ft_isdigit(char c);
char    **ft_split_lines(char *str, int *line_count);

#endif
