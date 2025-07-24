/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 21:58:50 by kreys             #+#    #+#             */
/*   Updated: 2025/07/24 22:08:11 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	res;
	int	prev_res;

	prev_res = 0;
	i = 0;
	while (++i < length)
	{
		res = f(tab[i - 1], tab[i]);
		if (res == 0 || res == prev_res)
			continue ;
		if (prev_res == 0)
			prev_res = res;
		else
			return (0);
	}
	return (1);
}
