/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:57:54 by kreys             #+#    #+#             */
/*   Updated: 2025/07/01 04:06:02 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	main(void)
{
	char	first;
	char	second;
	char	third;

	first = 47;
	while (++first <= '7')
	{
		second = first;
		while (++second <= '8')
		{
			third = second;
			while (++third <= '9')
			{
				write(1, &first, 1);
				write(1, &second, 1);
				write(1, &third, 1);
				if (first != '7' || second != '8' || third != '9')
					write(1, ", ", 2);
			}
		}
	}
	write(1, "\n", 1);
}
