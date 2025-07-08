/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:44:35 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 11:31:57 by kreys            ###   ########.fr       */
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
