/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:50:42 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 16:32:23 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_print_numbers(void)
{
	char	numb;

	numb = 47;
	while (numb++ < 57)
		write(1, &numb, 1);
}

int	main(void)
{
	ft_print_numbers();
	write(1, "\n", 1);
}
