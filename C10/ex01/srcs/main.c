/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 09:16:50 by kreys             #+#    #+#             */
/*   Updated: 2025/07/12 23:10:22 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include <libgen.h>
#include <string.h>
#include <errno.h>

void	read_fd(int fd)
{
	int		byte;
	char	buff[BUFSIZ];

	byte = read(fd, buff, BUFSIZ);
	while (byte > 0)
	{
		write(STDOUT_FILENO, buff, byte);
		byte = read(fd, buff, BUFSIZ);
	}
}

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

void	print_err(char *program_name, char *file_name)
{
	put_str(program_name, STDERR_FILENO, -1);
	put_str(": ", STDERR_FILENO, 2);
	put_str(file_name, STDERR_FILENO, -1);
	put_str(": ", STDERR_FILENO, 2);
	put_str(strerror(errno), STDERR_FILENO, -1);
	put_str("\n", STDERR_FILENO, 1);
}

void	cat_f(char *program_name, char *file_name)
{
	int		fd;

	if (file_name && file_name[0] == '-' && file_name[1] == '\0')
		fd = STDIN_FILENO;
	else
		fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		print_err(program_name, file_name);
		return ;
	}
	read_fd(fd);
	if (fd > 2)
		close(fd);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*base_name;

	if (argc == 1)
		read_fd(STDIN_FILENO);
	if (argc > 1)
	{
		i = 0;
		base_name = basename(argv[0]);
		while (argc > ++i)
			cat_f(base_name, argv[i]);
	}
	return (0);
}
