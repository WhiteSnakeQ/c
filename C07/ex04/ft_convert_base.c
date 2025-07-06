/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:05:58 by kreys             #+#    #+#             */
/*   Updated: 2025/07/04 23:56:52 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

int		str_len(char *str);
int		is_valid_base(char *base, int base_lens);
long	convert_str_to_dec(char *str, char *base, int base_lens);

char	*create_str(int size)
{
	char	*str;
	int		i;

	str = malloc((size * sizeof(char)) + sizeof(char));
	i = -1;
	while (str && ++i < size + 1)
		str[i] = '\0';
	return (str);
}

int	convert(long nbr, char *base, int size, char **str_to_ret)
{
	char	*next_char;

	if (nbr < 0)
		nbr = -nbr;
	if (nbr >= size)
	{
		next_char = (*str_to_ret + 1);
		convert(nbr / size, base, size, &next_char);
	}
	**str_to_ret = base[nbr % size];
}

void	str_reverse(char **str, int size)
{
	int		i;
	char	swap;
	char	*str2;

	i = -1;
	str2 = *str;
	while (size / 2 > ++i)
	{
		swap = str2[i];
		str2[i] = str2[size - 1 - i];
		str2[size - 1 - i] = swap;
	}
}

char	*convert_dec_to_str(int nbr, char *base, int base_lens)
{
	int		str_size;
	int		positive;
	long	nbr2;
	char	*str_to_ret;

	str_size = 1;
	positive = 1;
	nbr2 = nbr;
	if (nbr2 < 0 && str_size++ != -1)
	{
		nbr2 = -nbr2;
		positive = -positive;
	}
	while (nbr2 >= base_lens && str_size++ != -1)
		nbr2 /= base_lens;
	str_to_ret = create_str(str_size);
	if (str_to_ret)
	{
		convert(nbr, base, base_lens, &str_to_ret);
		if (positive == -1)
			str_to_ret[str_size - 1] = '-';
		str_reverse(&str_to_ret, str_size);
	}
	return (str_to_ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		positive;
	int		size_f;
	int		size_to;
	long	res;

	positive = 1;
	i = 0;
	size_f = str_len(base_from);
	size_to = str_len(base_to);
	if (is_valid_base(base_from, size_f) && is_valid_base(base_to, size_to))
		return (0);
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			positive = -positive;
		i++;
	}
	res = convert_str_to_dec(&nbr[i], base_from, size_f);
	if (positive < 0)
		res = -res;
	return (convert_dec_to_str(res, base_to, size_to));
}

int	main(void)
{
	char	*str;

	str = ft_convert_base("-+++--101010", "01", "0123456789");
	printf("%s\n", str);
	free(str);
}