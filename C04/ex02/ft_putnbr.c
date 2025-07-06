/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 06:24:50 by kreys             #+#    #+#             */
/*   Updated: 2025/07/02 06:28:42 by kreys            ###   ########.fr       */
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
