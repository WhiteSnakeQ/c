/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:13:12 by kreys             #+#    #+#             */
/*   Updated: 2025/07/01 19:17:04 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	ft_ultimate_div_mod(int *a, int *b)
{
	int value1;
	int	value2;

	value1 = *a;
	value2 = *b;

	*a = value1 / value2;
	*b = value1 % value2;
}
