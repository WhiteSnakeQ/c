/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 21:35:07 by kreys             #+#    #+#             */
/*   Updated: 2025/07/24 21:39:26 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	i = -1;
	result = malloc(sizeof(int) * length);
	if (!result)
		return (result);
	while (++i < length)
		result[i] = f(tab[i]);
	return (result);
}
