/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 04:02:18 by kreys             #+#    #+#             */
/*   Updated: 2025/07/12 22:59:55 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"

void	put_str(char *str, int fd, int size)
{
	int	i;

	if (size < 0)
	{
		i = 0;
		while (str && str[i])
			i++;
		write(fd, str, i);
	}
	else
		write(fd, str, size);
}

int	check_argv(int argc)
{
	int	err;

	err = 0;
	if (argc == 1)
	{
		put_str("File name missing.\n", STDERR_FILENO, 19);
		err = 1;
	}
	if (argc > 2)
	{
		put_str("Too many arguments.\n", STDERR_FILENO, 20);
		err = 1;
	}
	return (err);
}

int	open_file(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		put_str("Cannot read file.\n", STDERR_FILENO, 18);
	return (fd);
}

void	read_file(int fd)
{
	char	c[BUFSIZ];
	int		status;

	status = read(fd, &c, BUFSIZ);
	while (status > 0)
	{
		write(STDOUT_FILENO, &c, status);
		status = read(fd, &c, BUFSIZ);
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	if (check_argv(argc))
		return (0);
	fd = open_file(argv[1]);
	if (fd < 0)
		return (0);
	read_file(fd);
	close(fd);
	return (0);
}
