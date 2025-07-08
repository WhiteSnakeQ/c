/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:09:36 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 16:57:28 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 10;
	b = 3;
	div = 0;
	mod = 0;
	printf("a = %d - b = %d - mod = %d - div = %d\n", a, b, mod, div);
	ft_div_mod(a, b, &div, &mod);
	printf("a = %d - b = %d - mod = %d - div = %d\n", a, b, mod, div);
}
