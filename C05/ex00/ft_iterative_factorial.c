/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:44:18 by kreys             #+#    #+#             */
/*   Updated: 2025/07/09 21:08:25 by kreys            ###   ########.fr       */
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

int	main(void)
{
	int	i;

	i = 5;
	printf("factorial of %d is %d\n", i, ft_iterative_factorial(i));
	i = 1;
	printf("factorial of %d is %d\n", i, ft_iterative_factorial(i));
	i = 0;
	printf("factorial of %d is %d\n", i, ft_iterative_factorial(i));
	i = 2;
	printf("factorial of %d is %d\n", i, ft_iterative_factorial(i));
	i = 3;
	printf("factorial of %d is %d\n", i, ft_iterative_factorial(i));
	i = 10;
	printf("factorial of %d is %d\n", i, ft_iterative_factorial(i));
}
