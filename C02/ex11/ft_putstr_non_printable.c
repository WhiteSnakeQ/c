/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 01:27:42 by kreys             #+#    #+#             */
/*   Updated: 2025/07/12 22:53:32 by kreys            ###   ########.fr       */
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
	int				index;
	unsigned char	*str2;

	index = -1;
	str2 = (unsigned char *)str;
	while (str2 && str2[++index])
	{
		if (str2[index] >= 32 && str2[index] <= 126)
		{
			put_char(str2[index]);
		}
		else if (str2[index] < 32 || str2[index] == 127)
		{
			put_char('\\');
			put_char(HEXTAB[str2[index] / 16]);
			put_char(HEXTAB[str2[index] % 16]);
		}
	}
}

int	main(void)
{
	char str[40] = "qwewqe";

	str[2] = -49;
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	write(1, "\n", 1);
	ft_putstr_non_printable(str);
	write(1, "\n", 1);
}