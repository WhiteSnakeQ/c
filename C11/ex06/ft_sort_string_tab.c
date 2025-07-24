/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:42:50 by kreys             #+#    #+#             */
/*   Updated: 2025/07/24 22:51:05 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	swap_str(char **a, char **b)
{
	char	*replace;

	replace = *a;
	*a = *b;
	*b = replace;
}

int	strs_len(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int	sorted_index;
	int	search_index;
	int	size;

	size = strs_len(tab);
	sorted_index = -1;
	while (++sorted_index < size - 1)
	{
		search_index = sorted_index;
		while (++search_index < size)
		{
			if (ft_strcmp(tab[sorted_index], tab[search_index]) > 0)
				swap_str(&tab[sorted_index], &tab[search_index]);
		}
	}
}
