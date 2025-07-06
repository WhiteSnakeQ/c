/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:24:16 by kreys             #+#    #+#             */
/*   Updated: 2025/07/06 10:33:22 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_tail.h"
#include "stdio.h"
#include "fcntl.h"

void	print_header(char *str)
{
	put_str("==> ", STDOUT_FILENO, 4);
	if (str)
		put_str(str, STDOUT_FILENO, -1);
	else
		put_str("standard input", STDOUT_FILENO, 14);
	put_str(" <==\n", STDOUT_FILENO, 5);
}

int	get_file_size(char *file_name)
{
	char	buff[BUFSIZ];
	int		f_size;
	int		b_read;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	b_read = read(fd, buff, BUFSIZ);
	f_size = b_read;
	while (b_read > 0)
	{
		b_read = read(fd, buff, BUFSIZ);
		f_size += b_read;
	}
	return (f_size);
}

void	file_read(int fd, int byte_count, int file_size)
{
	char	buff[BUFSIZ];
	int		b_read;

	while (file_size > byte_count)
	{
		if (file_size - byte_count > BUFSIZ)
			b_read = read(fd, buff, BUFSIZ);
		else
			b_read = read(fd, buff, file_size - byte_count);
		if (b_read < 0)
			return ;
		file_size -= b_read;
	}
	while (file_size > BUFSIZ)
	{
		b_read = read(fd, buff, BUFSIZ);
		if (b_read < 0)
			return ;
		put_str(buff, STDOUT_FILENO, b_read);
		file_size -= BUFSIZ;
	}
	b_read = read(fd, buff, file_size);
	if (b_read < 0)
		return ;
	put_str(buff, STDOUT_FILENO, b_read);
}
