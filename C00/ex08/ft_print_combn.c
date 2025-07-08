/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 03:32:53 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 14:47:17 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	fill_str(char *str, int size)
{
	str[size] = '\0';
	while (size-- > 0)
		str[size] = '0' + size;
}

void	print_str(char *str, int size)
{
	static int	delim = 0;
	int			i;

	i = 0;
	if (delim == 0)
		delim++;
	else
		write(1, ", ", 2);
	while (i < size)
		write(1, &str[i++], 1);
}

void	next_numb(char *str, int index)
{
	if (str[index - 1] == '9' && index > 1)
	{
		next_numb(str, index - 1);
		while (str[index - 2] == '9')
			next_numb(str, index - 1);
		str[index - 1] = str[index - 2] + 1;
	}
	else
		str[index - 1]++;
}

void	ft_print_combn(int size)
{
	char	numb[11];

	if (size > 10 || size < 1)
		return ;
	fill_str(numb, size);
	while (numb[0] < 11 - size + '0')
	{
		print_str(numb, size);
		next_numb(numb, size);
	}
	write(1, "\n", 1);
}
