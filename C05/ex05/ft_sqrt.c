/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:10:16 by kreys             #+#    #+#             */
/*   Updated: 2025/07/02 22:10:36 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	found_sqrt(long nb, long m, int change, int try)
{
	long	c;

	if (change == 0)
		change = 1;
	if (try >= m)
		return (0);
	c = m * m;
	if (c == nb)
		return (m);
	if (c < nb)
		return (found_sqrt(nb, m + change, change / 2, m));
	else
		return (found_sqrt(nb, m - change, change / 2, try));
}

int	ft_sqrt(int nb)
{
	long		nb1;

	if (nb < 0)
		return (0);
	nb1 = nb;
	if (nb1 == 1)
		return (1);
	return (found_sqrt(nb1, nb1 / 2, nb1 / 4, 0));
}