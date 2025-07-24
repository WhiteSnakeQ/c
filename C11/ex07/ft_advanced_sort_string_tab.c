/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:50:01 by kreys             #+#    #+#             */
/*   Updated: 2025/07/24 22:51:29 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[sorted_index], tab[search_index]) > 0)
				swap_str(&tab[sorted_index], &tab[search_index]);
		}
	}
}
