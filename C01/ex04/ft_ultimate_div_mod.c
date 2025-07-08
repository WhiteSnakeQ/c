/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:13:12 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 16:59:10 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	value1;
	int	value2;

	value1 = *a;
	value2 = *b;
	*a = value1 / value2;
	*b = value1 % value2;
}

int	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 3;
	printf("before: a = %d - b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("after: a = %d - b = %d\n", a, b);
}
