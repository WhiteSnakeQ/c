/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:44:18 by kreys             #+#    #+#             */
/*   Updated: 2025/07/02 21:48:53 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	b;
	int	c;

	c = 0;
	if (nb < 0)
		return (0);
	b = 1;
	while (nb > 0)
	{
		b *= c + 1;
		nb--;
		c++;
	}
	return (b);
}