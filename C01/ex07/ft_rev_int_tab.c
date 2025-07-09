/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:28:41 by kreys             #+#    #+#             */
/*   Updated: 2025/07/09 19:41:26 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	ft_swap(int *a, int *b)
{
	int	replace;

	replace = *a;
	*a = *b;
	*b = replace;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;

	index = -1;
	while (size / 2 > ++index)
		ft_swap(&tab[index], &tab[size - 1 - index]);
}

int	main(void)
{
	int	tab[] = {1, 2, 3};
	int tab2[] = {1, 2, 3, 4};

	int	d = 3;
	printf("int arr size = %d\n", d);
	for (int i = 0; i < d; i++)
		printf("%d ", tab[i]);
	printf("\n\nint arr rev = %d\n", d);
	ft_rev_int_tab(tab, d);
	for (int i = 0; i < d; i++)
		printf("%d ", tab[i]);

	d = 4;
	printf("\n\nint arr size = %d\n", d);
	for (int i = 0; i < d; i++)
		printf("%d ", tab2[i]);
	printf("\n\nint arr rev = %d\n", d);
	ft_rev_int_tab(tab2, d);
	for (int i = 0; i < d; i++)
		printf("%d ", tab2[i]);
	printf("\n");

	ft_rev_int_tab(tab, 1);
	ft_rev_int_tab(tab, 0);
}
