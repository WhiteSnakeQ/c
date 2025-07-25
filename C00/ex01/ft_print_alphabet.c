/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:13:58 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 16:30:57 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_print_alphabet(void)
{
	char	letter;

	letter = 96;
	while (letter++ < 122)
	{
		write(1, &letter, 1);
	}
}

int	main(void)
{
	ft_print_alphabet();
	write(1, "\n", 1);
}
