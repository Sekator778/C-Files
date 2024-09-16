#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>

#define BUF_SIZE 30000

void ft_puterror(char *program_name, char *filename)
{
    write(2, basename(program_name), strlen(basename(program_name)));
    write(2, ": ", 2);
    write(2, filename, strlen(filename));
    write(2, ": ", 2);
    write(2, strerror(errno), strlen(strerror(errno)));
    write(2, "\n", 1);
}

int ft_display_file(char *program_name, char *filename)
{
    int fd;
    int ret;
    char buffer[BUF_SIZE];

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_puterror(program_name, filename);
        return (1);
    }
    while ((ret = read(fd, buffer, BUF_SIZE)) > 0)
        write(1, buffer, ret);
    if (ret < 0)
    {
        ft_puterror(program_name, filename);
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
        char buffer[BUF_SIZE];
        int ret;
        while ((ret = read(0, buffer, BUF_SIZE)) > 0)
            write(1, buffer, ret);
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        if (ft_display_file(argv[0], argv[i]))
            continue;
    }
    return (0);
}
