/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:09:25 by kreys             #+#    #+#             */
/*   Updated: 2025/07/20 19:49:41 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

char	**create_strs(int size);
void	print_strs(char **strs);
char	**free_strs(char **strs);
char	**part2(char **tab, int size);
int		get_size_world(char *str);
char	**ft_split(char *str, char *charset);
int		ft_atoi(char *str);

int	make_tab(char **tab, char **arg, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (ft_atoi(arg[i * 4 + j]) > size)
				return (1);
			tab[i][j] = arg[i * 4 + j][0];
		}
	}
	return (0);
}

char	**part1(int size, char *str)
{
	char	**arg;
	char	**tab;

	tab = create_strs(size);
	if (!tab)
		return (NULL);
	arg = ft_split(str, " ");
	if (!tab || !arg)
		return (free_strs(tab), NULL);
	if (make_tab(tab, arg, size))
	{
		free_strs(arg);
		return (free_strs(tab));
	}
	free_strs(arg);
	return (tab);
}

int	main(int argc, char **argv)
{
	char	**tab;
	char	**result;
	int		size;

	if (argc != 2)
		return (write(1, "Error\n", 6), 0);
	size = get_size_world(argv[1]);
	if (size < 4)
		return (write(1, "Error\n", 6), 0);
	tab = part1(size, argv[1]);
	if (!tab)
		return (write(1, "Error\n", 6), 0);
	result = part2(tab, size);
	if (!result)
	{
		free_strs(tab);
		return (write(1, "Error\n", 6), 0);
	}
	else
	{
		print_strs(result);
		free_strs(result);
	}
	free_strs(tab);
}
