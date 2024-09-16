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

void print_hex(unsigned char byte)
{
    const char hex[] = "0123456789abcdef";
    char output[2];
    output[0] = hex[byte / 16];
    output[1] = hex[byte % 16];
    write(1, output, 2);
}

void print_ascii(unsigned char byte)
{
    if (byte >= 32 && byte <= 126)
        write(1, &byte, 1); // Printable ASCII
    else
        write(1, ".", 1);  // Non-printable ASCII
}

void print_offset(int offset)
{
    char hex_offset[9];
    snprintf(hex_offset, 9, "%08x", offset);
    write(1, hex_offset, 8);
    write(1, "  ", 2);
}

void ft_hexdump(int fd, char *filename)
{
    unsigned char buffer[16];
    int ret;
    int offset = 0;

    while ((ret = read(fd, buffer, 16)) > 0)
    {
        // Print the offset
        print_offset(offset);

        // Print the hexadecimal values with spaces between bytes
        for (int i = 0; i < 16; i++)
        {
            if (i < ret)
            {
                print_hex(buffer[i]);
            }
            else
            {
                write(1, "  ", 2); // Padding for incomplete lines
            }
            write(1, " ", 1); // Add space after each byte
        }

        // Print the ASCII representation
        write(1, "|", 1);
        for (int i = 0; i < ret; i++)
            print_ascii(buffer[i]);
        write(1, "|\n", 2);

        offset += ret;
    }

    if (ret < 0)
        ft_puterror("ft_hexdump", filename);
}

int main(int argc, char **argv)
{
    int fd;

    if (argc < 2)
    {
        write(2, "Usage: ./ft_hexdump [file...]\n", 30);
        return (1);
    }

    // Handle each file passed as an argument
    for (int i = 1; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd < 0)
        {
            ft_puterror(argv[0], argv[i]);
            continue;
        }

        ft_hexdump(fd, argv[i]);
        close(fd);
    }

    return (0);
}
