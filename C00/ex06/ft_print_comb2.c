/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:45:33 by kreys             #+#    #+#             */
/*   Updated: 2025/07/01 03:09:35 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	put_string(char *str1, char *str2)
{
	static char	delim = 0;

	if (delim == 0)
		delim++;
	else
		write(1, ", ", 2);
	write(1, &str1[0], 1);
	write(1, &str1[1], 1);
	write(1, " ", 1);
	write(1, &str2[0], 1);
	write(1, &str2[1], 1);
}

void	ft_print_comb2(void)
{
	char	first[3];
	char	second[3];

	first[0] = '0';
	first[1] = '0';
	while (first[0] < '9' || first[1] < '9')
	{
		second[1] = first[1] + 1;
		second[0] = first[0];
		while (second[0] <= '9' && second[1] <= 58)
		{
			put_string(first, second);
			if (++second[1] == 58)
			{
				second[0]++;
				second[1] = '0';
			}
		}
		if (++first[1] == 58)
		{
			first[0]++;
			first[1] = '0';
		}
	}
	write(1, "\n", 1);
}
