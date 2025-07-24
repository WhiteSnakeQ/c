/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 21:52:31 by kreys             #+#    #+#             */
/*   Updated: 2025/07/24 21:56:17 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (++i < length)
	{
		if (f(tab[i]))
			res++;
	}
	return (res);
}
