/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:22:43 by kreys             #+#    #+#             */
/*   Updated: 2025/07/24 22:27:14 by kreys            ###   ########.fr       */
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
