/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 07:19:41 by kreys             #+#    #+#             */
/*   Updated: 2025/07/06 10:44:40 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_tail.h"
#include "stdio.h"
#include "string.h"
#include "errno.h"

void	prnt_f_err(char *program_name, char *arg_name, int mod)
{
	put_str(program_name, STDERR_FILENO, -1);
	put_str(": ", STDERR_FILENO, 2);
	put_str(arg_name, STDERR_FILENO, -1);
	put_str(": ", STDERR_FILENO, 2);
	put_str(strerror(errno), STDERR_FILENO, -1);
	if (mod > 1)
		write(STDERR_FILENO, "\n", 1);
}

void	print_parse_error(char *name, char *error, char *error2)
{
	put_str(name, STDERR_FILENO, -1);
	put_str(": ", STDERR_FILENO, 2);
	put_str(error, STDERR_FILENO, -1);
	put_str("'", STDERR_FILENO, 1);
	put_str(error2, STDERR_FILENO, -1);
	put_str("'\n", STDERR_FILENO, 2);
}

int	parse_error(char **argv, int status)
{
	char	*error;
	char	*error2;

	error = (void *)0;
	if (argv[1] && str_len(argv[1]) >= 2)
		error2 = argv[1] + 1;
	else
		error2 = argv[1];
	if (status == LOWARG)
		return (-1);
	else if (status == OPTREQARG)
		error = OPTREQARGSTR;
	else if (status == INVOPT)
		error = INVOPTSTR;
	else if (status == INVNUMBYT)
	{
		error = INVNUMBYTSTR;
		if (str_len(argv[1]) == 2)
			error2 = argv[2];
		else
			error2 = argv[1] + 2;
	}
	if (error && error2)
		print_parse_error(basename(argv[0]), error, error2);
	return (status);
}

int	check_argv(int argc, char **argv)
{
	int	size_argv1;

	size_argv1 = str_len(argv[1]);
	if (argc < 2)
		return (LOWARG);
	else if (ft_strncmp(argv[1], "-c", 2) != 0)
		return (INVOPT);
	else if (argc == 2 && size_argv1 == 2)
		return (OPTREQARG);
	else if (argc >= 3 && size_argv1 > 2 && is_numbr(argv[1] + 2) == -1)
		return (INVNUMBYT);
	else if (argc >= 3 && is_numbr(argv[2]) && size_argv1 == 2)
		return (INVNUMBYT);
	else if (argc == 2 && is_numbr(argv[1] + 2))
		return (INVNUMBYT);
	return (0);
}
