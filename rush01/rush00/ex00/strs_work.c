/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:09:27 by kreys             #+#    #+#             */
/*   Updated: 2025/07/20 01:16:38 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"

void	fill_str(char *str, char to_fill, int size)
{
	int	i;

	i = -1;
	while (size > ++i)
		str[i] = to_fill;
}

char	**free_strs(char **strs)
{
	int	i;

	i = -1;
	if (strs)
	{
		while (strs[++i])
			free(strs[i]);
		free(strs);
	}
	return (NULL);
}

char	**create_strs(int size)
{
	char	**result;
	int		i;

	result = malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (result);
	i = -1;
	while (++i < size)
	{
		result[i] = malloc(sizeof(char) * (size + 1));
		if (!result[i])
			return (free_strs(result));
		fill_str(result[i], '\0', size + 1);
	}
	result[size] = NULL;
	return (result);
}

void	fill_strs(char **tab, char to_fill, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		fill_str(tab[i], to_fill, size);
}

void	print_strs(char **strs)
{
	int	i;
	int	j;

	i = -1;
	while (strs && strs[++i])
	{
		j = -1;
		while (strs[i][++j])
			write(1, &strs[i][j], 1);
		write(1, "\n", 1);
	}
}
