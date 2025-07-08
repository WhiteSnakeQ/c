/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:01:38 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 19:47:52 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	number;

	number = nb;
	if (power < 0)
		return (0);
	if (power == 0 || nb == 1)
		return (1);
	if (power > 1)
		return (number * ft_recursive_power(nb, power - 1));
	return (number);
}

int	main(void)
{
	int	i;
	int	power;

	i = 2;
	power = 5;
	printf("digit = %d | power = %d\nresult: %d\n\n", i, power, ft_recursive_power(i, power));
	power = 2;
	printf("digit = %d | power = %d\nresult: %d\n\n", i, power, ft_recursive_power(i, power));	
	power = 0;
	printf("digit = %d | power = %d\nresult: %d\n\n", i, power, ft_recursive_power(i, power));	
	power = 1;
	printf("digit = %d | power = %d\nresult: %d\n\n", i, power, ft_recursive_power(i, power));	
	power = -1;
	printf("digit = %d | power = %d\nresult: %d\n\n", i, power, ft_recursive_power(i, power));
	power = 10;
	printf("digit = %d | power = %d\nresult: %d\n\n", i, power, ft_recursive_power(i, power));	
}
