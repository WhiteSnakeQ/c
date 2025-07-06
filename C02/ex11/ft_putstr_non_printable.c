/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 01:27:42 by kreys             #+#    #+#             */
/*   Updated: 2025/07/02 01:36:45 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		index;
	char	*hex_tab;

	hex_tab = "0123456789abcdef";
	index = -1;
	while (str && str[++index])
	{
		if (str[index] >= 32 && str[index] <= 126)
		{
			put_char(str[index]);
		}
		else
		{
			put_char('\\');
			put_char(hex_tab[str[index] / 16]);
			put_char(hex_tab[str[index] % 16]);
		}
	}
}
