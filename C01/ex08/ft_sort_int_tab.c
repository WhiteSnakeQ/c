/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:44:35 by kreys             #+#    #+#             */
/*   Updated: 2025/07/09 19:43:04 by kreys            ###   ########.fr       */
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	sorted_index;
	int	search_index;

	sorted_index = -1;
	while (++sorted_index < size - 1)
	{
		search_index = sorted_index;
		while (++search_index < size)
		{
			if (tab[sorted_index] > tab[search_index])
				ft_swap(&tab[sorted_index], &tab[search_index]);
		}
	}
}

int	main(void)
{
	int	tab[] = {10, -10, 20, -20, 5, 4, 0};
	int tab2[] = {37, 35, 1, 6, 3, -20, -2147483648, 2147483647};
	int	d;

	d = 2;
	printf("int arr size = %d\n", d);
	for (int i = 0; i < d; i++)
		printf("%d ", tab[i]);
	printf("\n\nint arr sort = %d\n", d);
	ft_sort_int_tab(tab, d);
	for (int i = 0; i < d; i++)
		printf("%d ", tab[i]);

	d = 9;
	printf("\n\nint arr size = %d\n", d);
	for (int i = 0; i < d; i++)
		printf("%d ", tab2[i]);
	printf("\n\nint arr sort = %d\n", d);
	ft_sort_int_tab(tab2, d);
	for (int i = 0; i < d; i++)
		printf("%d ", tab2[i]);
	printf("\n");

	ft_sort_int_tab(tab, 1);
	ft_sort_int_tab(tab, 0);
}
