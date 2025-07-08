/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:28:41 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 17:09:00 by kreys            ###   ########.fr       */
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
	int	tab[] = {1, 2, 3, 4, 5, 6, 7};
	int tab2[] = {1, 2, 3, 4, 5, 6};

	printf("int arr size = 7\n");
	for (size_t i = 0; i < 7; i++)
		printf("%d ", tab[i]);
	printf("\n\nint arr rev = 7\n");
	ft_rev_int_tab(tab, 7);
	for (size_t i = 0; i < 7; i++)
		printf("%d ", tab[i]);


	printf("\n\nint arr size = 6\n");
	for (size_t i = 0; i < 6; i++)
		printf("%d ", tab2[i]);
	printf("\n\nint arr rev = 6\n");
	ft_rev_int_tab(tab2, 6);
	for (size_t i = 0; i < 6; i++)
		printf("%d ", tab2[i]);
	printf("\n");

	ft_rev_int_tab(tab, 1);
	ft_rev_int_tab(tab, 0);
}
