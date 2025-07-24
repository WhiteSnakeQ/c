/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:08:40 by kreys             #+#    #+#             */
/*   Updated: 2025/07/24 22:28:28 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		ft_atoi(char *str);
void	plus(int val1, int val2);
void	minus(int val1, int val2);
void	multp(int val1, int val2);
void	devision(int val1, int val2);
void	modul(int val1, int val2);

void	do_op(int val1, int val2, char operator)
{
	if (operator == '+')
		plus(val1, val2);
	else if (operator == '-')
		minus(val1, val2);
	else if (operator == '*')
		multp(val1, val2);
	else if (operator == '/')
	{
		if (val2 == 0)
			write(1, "Stop : division by zero", 23);
		else
			devision(val1, val2);
	}
	else if (operator == '%')
	{
		if (val2 == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			modul(val1, val2);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	do_op(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2][0]);
}
