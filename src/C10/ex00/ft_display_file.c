#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

void ft_puterror(char *str)
{
    while (*str)
        write(2, str++, 1);
}

int ft_display_file(char *filename)
{
    int fd;
    int ret;
    char buffer[BUF_SIZE];

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_puterror("Cannot read file.\n");
        return (1);
    }
    while ((ret = read(fd, buffer, BUF_SIZE)) > 0)
        write(1, buffer, ret);
    if (ret < 0)
    {
        ft_puterror("Cannot read file.\n");
        close(fd);
        return (1);
    }
    close(fd);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_puterror("File name missing.\n");
        return (1);
    }
    else if (argc > 2)
    {
        ft_puterror("Too many arguments.\n");
        return (1);
    }
    return (ft_display_file(argv[1]));
}
