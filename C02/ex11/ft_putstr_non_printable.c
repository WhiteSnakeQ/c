/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 01:27:42 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 18:11:22 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

#define HEXTAB "0123456789abcdef"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		index;

	index = -1;
	while (str && str[++index])
	{
		if (str[index] >= 32 && str[index] <= 126)
		{
			put_char(str[index]);
		}
		else if (str[index] < 32 || str[index] == 127)
		{
			put_char('\\');
			put_char(HEXTAB[str[index] / 16]);
			put_char(HEXTAB[str[index] % 16]);
		}
	}
}

int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	write(1, "\n", 1);
	ft_putstr_non_printable("He\vll\to wo\br\tld\n");
	write(1, "\n", 1);
}