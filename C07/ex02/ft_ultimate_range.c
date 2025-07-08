/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 05:42:26 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 20:09:28 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

int ft_ultimate_range(int **range, int min, int max)
{
	long	tab_size;
	long	i;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	tab_size = max - min;
	*range = malloc(tab_size * sizeof(int));
	if (!range)
		return (-1);
	i = -1;
	while (tab_size > ++i)
		(*range)[i] = min + i;
	return (i);
}

int	main(void)
{
	int	*i;
	
	printf("%d\n", ft_ultimate_range(&i, 10, 15));
	printf("%d\n", ft_ultimate_range(&i, -10, 15));
}