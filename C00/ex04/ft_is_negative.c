/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:53:24 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 16:36:36 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}

int	main(void)
{
	printf(" 42");
	ft_is_negative(42);
	printf("\n 0");
	ft_is_negative(0);
	printf("\n -42");
	ft_is_negative(-42);
	printf("\n");
}
