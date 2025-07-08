/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:06:39 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 16:54:35 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	i;
	int	b;

	i = 10;
	b = 5;
	printf("i = %d | b = %d -- before func\n", i, b);
	ft_swap(&i, &b);
	printf("i = %d  | b = %d -- after func\n", i, b);
}
