/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:28:41 by kreys             #+#    #+#             */
/*   Updated: 2025/07/01 19:48:53 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int replace;

	replace = *a;
	*a = *b;
	*b = replace;
}

void ft_rev_int_tab(int *tab, int size)
{
	int	index;

	index = -1;

	if (!tab)
		return ;
	while (size / 2 > ++index )
		ft_swap(&tab[index], &tab[size - 1 - index]);
}
