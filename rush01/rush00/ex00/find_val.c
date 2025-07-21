/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:09:19 by kreys             #+#    #+#             */
/*   Updated: 2025/07/20 01:17:11 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

void	fill_strs(char **tab, char to_fill, int size);
char	**create_strs(int size);
char	**free_strs(char **strs);
char	**get_all_poss_var(int size);
char	*ft_strcpy(char *dest, char *src);
int		fill_min_max(char **result, char **tab, int size);
int		str_len(char *str);
int		check_all(char **result, char **tab);

int	get_variants(int size)
{
	int	res;

	res = 1;
	while (size > 1)
		res *= size--;
	return (res);
}

int	put_new_var(char **result, char *all_var, int row, char **tab)
{
	int		i;
	int		size;
	int		visibility;
	char	max;

	i = -1;
	max = '0';
	size = str_len(result[0]);
	visibility = tab[2][row] - '0';
	while (++i < size)
	{
		if (all_var[i] > max)
		{
			visibility--;
			max = all_var[i];
		}
	}
	if (visibility == 0)
		return (0);
	else
		return (1);
}

int	start_algoritm(char **result, char **tab, int row, char **all_p_v)
{
	int		y;
	int		all_p_v_s;
	int		len;

	len = str_len(result[0]);
	if (row >= len)
	{
		if (!check_all(result, tab))
			return (0);
		return (1);
	}
	all_p_v_s = get_variants(len);
	y = -1;
	while (++y < all_p_v_s)
	{
		if (!put_new_var(result, all_p_v[y], row, tab))
		{
			ft_strcpy(result[row], all_p_v[y]);
			if (!start_algoritm(result, tab, row + 1, all_p_v))
				return (0);
		}
	}
	return (1);
}

char	**part2(char **tab, int size)
{
	char	**result;
	char	**posible_var;

	result = create_strs(size);
	if (!result)
		return (result);
	fill_strs(result, '0', size);
	posible_var = get_all_poss_var(size);
	if (start_algoritm(result, tab, 0, posible_var))
		return (free_strs(result), free_strs(posible_var));
	free_strs(posible_var);
	return (result);
}
