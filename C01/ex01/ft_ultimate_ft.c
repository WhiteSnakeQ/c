/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:01:58 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 16:52:34 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int	main(void)
{
	int	i;
	int	*i1;
	int	**i2;
	int	***i3;
	int	****i4;
	int	*****i5;
	int	******i6;
	int	*******i7;
	int	********i8;

	i1 = &i;
	i2 = &i1;
	i3 = &i2;
	i4 = &i3;
	i5 = &i4;
	i6 = &i5;
	i7 = &i6;
	i8 = &i7;
	i = 10;
	printf("i = %d before func\n", i);
	ft_ultimate_ft(&i8);
	printf("i = %d after func\n", i);
}
