/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:26:35 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 16:31:53 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_print_reverse_alphabet(void)
{
	char	letter;

	letter = 123;
	while (letter-- > 97)
	{
		write(1, &letter, 1);
	}
}

int	main(void)
{
	ft_print_reverse_alphabet();
	write(1, "\n", 1);
}
