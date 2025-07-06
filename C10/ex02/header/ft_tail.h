/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:57:29 by kreys             #+#    #+#             */
/*   Updated: 2025/07/06 10:17:56 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include "libgen.h"
# include "unistd.h"

# define LOWARG -1
# define LOWARGSTR ""

# define OPTREQARG -2
# define OPTREQARGSTR "option requires an argument -- "

# define INVOPT -3
# define INVOPTSTR "invalid option -- "

# define INVNUMBYT -4
# define INVNUMBYTSTR "invalid number of bytes: "

int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		is_numbr(char *str);
int		str_len(char *str);
int		check_argv(int argc, char **argv);
int		parse_error(char **argv, int status);
int		ft_atoi(char *str);
int		get_file_size(char *file_name);

void	put_str(char *str, int fd, int size);
void	tail_f(int argc, char **argv, int byte_nbr);
void	file_read(int fd, int byte_count, int file_size);
void	print_header(char *str);
void	prnt_f_err(char *program_name, char *arg_name, int mod);

#endif