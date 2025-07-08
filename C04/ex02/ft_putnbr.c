/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 06:24:50 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 19:19:19 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void ft_putnbr(int nb)
{
	long	numb;
	int		to_write;

	numb = nb;
	if (nb < 0)
	{
		numb = -numb;
		write(1, "-", 1);
	}
	if (numb >= 10)
		ft_putnbr(numb / 10);
	to_write = '0' + numb % 10;
	write(1, &to_write, 1);
}

int	main(void)
{
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-42);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
}