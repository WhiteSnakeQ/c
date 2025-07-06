/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:06:34 by kreys             #+#    #+#             */
/*   Updated: 2025/07/04 23:52:02 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base, int base_lens)
{
	int	i;
	int	curr;

	i = -1;
	if (!base || base_lens < 2)
		return (1);
	while (base && ++i < base_lens)
	{
		curr = i;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (base[i] < 32 || base[i] > 126)
			return (1);
		while (++curr < base_lens)
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

int	get_dec_fr_base(int base_val, int mult_c, int base_lens)
{
	if (mult_c > 0)
		return (get_dec_fr_base(base_val, --mult_c, base_lens) * base_lens);
	return (base_val);
}

long	convert_str_to_dec(char *str, char *base, int base_lens)
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
		numb += get_dec_fr_base(base_val, str_size - (i + 1), base_lens);
	}
	return (numb);
}
