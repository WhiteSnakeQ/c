/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 03:32:39 by kreys             #+#    #+#             */
/*   Updated: 2025/07/05 03:41:41 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strs_to_tab.h"
#include "stdio.h"
#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int		size;
	int		i;
	char	*dup;

	i = -1;
	size = str_len(src);
	dup = malloc((size * sizeof(char)) + sizeof(char));
	if (!dup)
		return (NULL);
	dup[size] = '\0';
	while (++i < size)
		dup[i] = src[i];
	return (dup);
}
struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*structs;

	structs = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (structs)
	{
		i = -1;
		while (++i < ac)
		{
			structs[i].size = str_len(av[i]);
			structs[i].str = av[i];
			structs[i].copy = ft_strdup(av[i]);
		}
		structs[i].str = NULL;
	}
	return (structs);
}