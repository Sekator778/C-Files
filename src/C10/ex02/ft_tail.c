#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>

void ft_puterror(char *program_name, char *filename)
{
    write(2, basename(program_name), strlen(basename(program_name)));
    write(2, ": ", 2);
    write(2, filename, strlen(filename));
    write(2, ": ", 2);
    write(2, strerror(errno), strlen(strerror(errno)));
    write(2, "\n", 1);
}

void ft_tail(int fd, char *filename, int bytes)
{
    char *buffer;
    int file_size;
    int ret;

    // Calculate file size using lseek
    file_size = lseek(fd, 0, SEEK_END);
    if (file_size < 0)
    {
        ft_puterror("ft_tail", filename);
        return;
    }

    // If the file size is less than the requested bytes, adjust bytes to file size
    if (file_size < bytes)
        bytes = file_size;

    // Move the file pointer to the correct position
    if (lseek(fd, file_size - bytes, SEEK_SET) < 0)
    {
        ft_puterror("ft_tail", filename);
        return;
    }

    // Allocate buffer for the required number of bytes
    buffer = (char *)malloc(bytes + 1);  // +1 to ensure null termination
    if (!buffer)
    {
        ft_puterror("ft_tail", filename);
        return;
    }

    // Read the last bytes into the buffer and write them to the standard output
    ret = read(fd, buffer, bytes);
    if (ret > 0)
    {
        buffer[ret] = '\0';  // Null-terminate the buffer for safety
        write(1, buffer, ret);
    }
    else
    {
        ft_puterror("ft_tail", filename);
    }

    free(buffer);
}

int main(int argc, char **argv)
{
    int fd, bytes;
    char *filename;

    if (argc < 4 || strcmp(argv[1], "-c") != 0)
    {
        write(2, "Usage: ./ft_tail -c [bytes] [file...]\n", 38);
        return (1);
    }

    bytes = atoi(argv[2]); // Convert the byte count argument
    if (bytes <= 0)
    {
        write(2, "Error: Invalid byte count\n", 26);
        return (1);
    }

    // Handle each file passed as an argument
    for (int i = 3; i < argc; i++)
    {
        filename = argv[i];
        fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            ft_puterror(argv[0], filename);
            continue;
        }

        if (argc > 4)
        {
            // Print the filename if more than one file is processed
            write(1, "==> ", 4);
            write(1, filename, strlen(filename));
            write(1, " <==\n", 5);
        }

        ft_tail(fd, filename, bytes);
        close(fd);

        if (i < argc - 1)
            write(1, "\n", 1); // Print a newline between multiple files
    }

    return (0);
}
