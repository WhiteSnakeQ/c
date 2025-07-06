/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 05:33:57 by kreys             #+#    #+#             */
/*   Updated: 2025/07/04 05:48:57 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

int	*ft_range(int min, int max)
{
	int	tab_size;
	int	i;
	int	*tab;

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
	ft_range(10, 15);
}