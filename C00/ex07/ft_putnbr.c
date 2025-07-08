/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 03:11:28 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 16:44:36 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"

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

int	main(void)
{
	ft_putnbr(42);
	printf("\n");
	ft_putnbr(-42);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
}
