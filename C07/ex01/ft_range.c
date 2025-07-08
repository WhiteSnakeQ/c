/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 05:33:57 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 20:05:26 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

int	*ft_range(int min, int max)
{
	long	tab_size;
	int		i;
	int		*tab;

	if (max <= min)
		return (NULL);
	tab_size = max - min;
	tab = malloc(tab_size * sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	while (tab_size > ++i)
		tab[i] = min + i;
	return (tab);	
}

int	main(void)
{
	int	*tab;
	long	min;
	long	max;

	min = 10;
	max = 15;
	tab = ft_range(min, max);
	for (size_t i = 0; i < max - min; i++)
	{
		printf("%d\n", tab[i]);
	}

	printf("\n\n");
	
	min = -10;
	max = 15;
	tab = ft_range(min, max);
	for (size_t i = 0; i < max - min; i++)
	{
		printf("%d\n", tab[i]);
	}
}
