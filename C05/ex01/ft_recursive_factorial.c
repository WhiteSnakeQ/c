/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:16:41 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 19:45:31 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

int	main(void)
{
	int	i;

	i = 5;
	printf("factorial of %d is %d\n", i, ft_recursive_factorial(i));
	i = 1;
	printf("factorial of %d is %d\n", i, ft_recursive_factorial(i));
	i = 0;
	printf("factorial of %d is %d\n", i, ft_recursive_factorial(i));
	i = 2;
	printf("factorial of %d is %d\n", i, ft_recursive_factorial(i));
	i = 3;
	printf("factorial of %d is %d\n", i, ft_recursive_factorial(i));
	i = 10;
	printf("factorial of %d is %d\n", i, ft_recursive_factorial(i));
	i = -1;
	printf("factorial of %d is %d\n", i, ft_recursive_factorial(i));
}
