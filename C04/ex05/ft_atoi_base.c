/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:55:03 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 19:37:54 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	is_valid_base(char *base, int size)
{
	int	i;
	int	curr;

	i = -1;
	if (!base || size < 2)
		return (1);
	while (base && ++i < size)
	{
		curr = i;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (base[i] < 33 || base[i] > 126)
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

int	find_char(char *str, char to_find)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == to_find)
			return (i);
	}
	return (-1);
}

int	get_dec_fr_base(int base_val, int mult_c, int size_b)
{
	if (mult_c > 0)
		return (get_dec_fr_base(base_val, --mult_c, size_b) * size_b);
	return (base_val);
}

long	convert_str_to_dec(char *str, char *base, int size)
{
	int		i;
	int		str_size;
	int		base_val;
	long	numb;

	i = -1;
	numb = 0;
	str_size = 0;
	while (str[str_size] && find_char(base, str[str_size]) >= 0)
		str_size++;
	while (str && str[++i])
	{
		base_val = find_char(base, str[i]);
		if (base_val < 0)
			return (numb);
		numb += get_dec_fr_base(base_val, str_size - (i + 1), size);
	}
	return (numb);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		positive;
	int		size;
	long	res;

	positive = 1;
	i = 0;
	size = 0;
	while (base && base[size])
		size++;
	if (is_valid_base(base, size))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			positive = -positive;
		i++;
	}
	res = convert_str_to_dec(&str[i], base, size);
	if (positive < 0)
		res = -res;
	return (res);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("+-00000 1 1010", "01"));
	printf("%d\n", ft_atoi_base("+-101010", "10"));
	printf("%d\n", ft_atoi_base(" \t \t +101010", "01"));
	printf("%d\n", ft_atoi_base("+-2147483648", "0123456789"));
	printf("%d\n", ft_atoi_base("+2147483647", "0123456789"));

	printf("%d\n", ft_atoi_base("+2147483647", "01123456789"));
	printf("%d\n", ft_atoi_base("+2147483647", "01+23456789"));
	printf("%d\n", ft_atoi_base("+2147483647", "0123-456789"));
	printf("%d\n", ft_atoi_base("+2147483647", "012345 6789"));
	printf("%d\n", ft_atoi_base("+2147483647", "012345  6789"));
}
