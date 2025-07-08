/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 06:50:10 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 20:24:49 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	curr;
	int	size;

	i = -1;
	size = str_len(base);
	if (!base || size < 2)
		return (1);
	while (base && ++i < size)
	{
		curr = i;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (base[i] < 32 || base[i] > 126)
			return (1);
		while (++curr < size)
		{
			if (base[curr] == base[i])
				return (1);
			curr ++;
		}
	}
	return (0);
}

void	convert(long nbr, char *base, int size)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= size)
		convert(nbr / size, base, size);
	write(1, &base[nbr % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (is_valid_base(base))
		return ;
	convert((long)nbr, base, str_len(base));
}

int	main(void)
{
	ft_putnbr_base(42, "0123456789abvdef");
	printf("\n");
	ft_putnbr_base(-10, "0123456789abvdef");
	printf("\n");
	ft_putnbr_base(2147483647, "0123456789abcdef");
	printf("\n");
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	printf("\n");
	ft_putnbr_base(42, "0123456789");
	printf("\n");
	ft_putnbr_base(-10, "0123456789");
	printf("\n");
	ft_putnbr_base(2147483647, "0123456789");
	printf("\n");
	ft_putnbr_base(-2147483648, "0123456789");
	printf("\n");
	ft_putnbr_base(0, "0123456789");
	printf("\n");
	ft_putnbr_base(0, "0123456789abccdef");
	printf("(nothing)\n");
	ft_putnbr_base(0, "0123456789ab+cdef");
	printf("(nothing)\n");
	ft_putnbr_base(0, "0123456789ab-cdef");
	printf("(nothing)\n");
	ft_putnbr_base(0, "0");
	printf("(nothing)\n");
	ft_putnbr_base(0, "");
	printf("(nothing)\n");
}
