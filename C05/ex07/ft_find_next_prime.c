/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:57:59 by kreys             #+#    #+#             */
/*   Updated: 2025/07/02 22:14:33 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nbr)
{
	int		limit;
	int		dev;

	dev = 5;
	limit = nbr / 2;
	if (nbr == 2 || nbr == 3)
		return (1);
	if (nbr < 2 || !(nbr % 2) || !(nbr % 3))
		return (0);
	while (dev <= limit)
	{
		if (!(nbr % dev++))
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}