#include "../headers/global.h"

int	return_exit(char *name)
{
	char *e;

	e = ft_strjoin("ft_hexdump: ", name);
	e = ft_strjoin(e, ": No such file or directory\n");
	return (write(1, e, ft_strlen(e)));
}

int	read_c(char *name)
{
	int		line;
	int		fd;
	int		r;
	int		i;
	char	buf[16];

	if ((fd = open(name, O_RDONLY)) == -1)
		return (return_exit(name));
	line = 0;
	while ((r = read(fd, buf, 16)))
	{
		ft_puthex_filled(line, 7);
		write(1, " ", 1);
		i = -1;
		while (++i < r)
		{
			if (buf[i] < 16)
				write(1, "0", 1);
			ft_puthex(buf[i]);
			write(1, " ", 1);
			if (i > 0 && i % 8 == 0)
				write(1, " ", 1);
		}
		while (i++ < 16)
		{
			write(1, "   ", 3);
			if (i > 0 && i < 16 && i % 8 == 0)
				write(1, " ", 1);
		}
		i = -1;
		write(1, " |", 2);
		while (++i < r)
			if (buf[i] > 126 || buf[i] < 32)
				write(1, ".", 1);
			else
				write(1, &buf[i], 1);
		write(1, "|\n", 2);
		line += r;
	}
	ft_puthex_filled(line, 7);
	write(1, "\n", 1);
	return (0);
}

int	read_without(char *name)
{
	int		line;
	int		fd;
	int		r;
	int		i;
	char	buf[16];

	if ((fd = open(name, O_RDONLY)) == -1)
		return (return_exit(name));
	line = 0;
	while ((r = read(fd, buf, 16)))
	{
		ft_puthex_filled(line, 7);
		write(1, " ", 1);
		i = -1;
		while (++i < r)
		{
			if (buf[i] < 16)
				write(1, "0", 1);
			ft_puthex(buf[i]);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
		line += r;
	}
	ft_puthex_filled(line, 7);
	write(1, "\n", 1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	option;

	option = 0;
	if (ac > 1 && ft_strcmp(av[1], "-C"))
		option = 1;
	i = option + 1;
	while (i < ac)
	{
		if (option)
			read_c(av[i]);
		else
			read_without(av[i]);
		i++;
	}
	return (0);
}
