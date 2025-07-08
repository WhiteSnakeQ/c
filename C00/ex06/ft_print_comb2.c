/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:45:33 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 14:53:03 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putnbr(int n)
{
	long	numb;
	char	last_nbr;

	numb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		numb = -numb;
	}
	if (numb > 9)
		ft_putnbr(numb / 10);
	last_nbr = numb % 10 + '0';
	write(1, &last_nbr, 1);
}

void	put_numb(int digit)
{
	if (digit > 9)
		ft_putnbr(digit);
	else
	{
		ft_putnbr(0);
		ft_putnbr(digit);
	}
}

void	put_numbers(int digit1, int digit2)
{
	static int	delim = 0;

	if (delim++ > 0)
		write(1, ", ", 2);
	put_numb(digit1);
	write(1, " ", 1);
	put_numb(digit2);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = -1;
	while (++first < 99)
	{
		second = first;
		while (++second < 100)
			put_numbers(first, second);
	}
	write(1, "\n", 1);
}
