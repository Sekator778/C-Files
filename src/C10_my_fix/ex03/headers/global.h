#ifndef GLOBAL_H
# define GLOBAL_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_strjoin(const char *s1, const char *s2);
void	ft_puthex_filled(long v, int width);
void	ft_puthex(long v);

#endif
