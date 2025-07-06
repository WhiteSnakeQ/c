/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:12:35 by kreys             #+#    #+#             */
/*   Updated: 2025/07/07 01:04:26 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_tail.h"
#include "fcntl.h"

void	read_std(int byte_nb, int mod)
{
	if (mod > 1)
		print_header(NULL);
	if (byte_nb > -1)
		put_str("Lolo\n", STDOUT_FILENO, 5);
}

void	tail_f2(char *arg, char *name, int byte_nbr, int mod)
{
	int			file_size;
	int			fd;
	static int	i = -1;

	i++;
	if (ft_strncmp(arg, "-", 2) == 0)
	{
		if (i > 0)
			put_str("\n", STDOUT_FILENO, 1);
		read_std(byte_nbr, mod);
		return ;
	}
	file_size = get_file_size(arg);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		prnt_f_err(name, arg, mod);
	else
	{
		if (i > 0)
			put_str("\n", STDOUT_FILENO, 1);
		if (mod > 1)
			print_header(arg);
		file_read(fd, byte_nbr, file_size);
		close(fd);
	}
}

void	tail_f(int argc, char **argv, int byte_nbr)
{
	int		i;
	int		s_argv;

	s_argv = 3;
	if (str_len(argv[1]) != 2)
		s_argv = 2;
	i = -1;
	while (argc - s_argv > ++i)
	{
		if (ft_strncmp(argv[i + s_argv], "-", 2) == 0)
			tail_f2("-", basename(argv[0]), byte_nbr, argc - s_argv);
		else
			tail_f2(argv[i + s_argv], basename(argv[0]), \
				byte_nbr, argc - s_argv);
	}
	if ((argc == 3 && s_argv == 3) || argc == 2)
		tail_f2("-", basename(argv[0]), byte_nbr, argc - s_argv);
}
