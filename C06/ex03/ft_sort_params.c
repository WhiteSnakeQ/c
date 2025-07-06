/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 04:57:00 by kreys             #+#    #+#             */
/*   Updated: 2025/07/04 05:18:39 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"

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

void	print_argv(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[j][i])
			write(1, &argv[j][i++], 1);
		write(1, "\n", 1);
	}
}

void	sort_argv(int size, char **argv)
{
	int	sorted_index;
	int	search_index;

	sorted_index = 0;
	while (++sorted_index < size - 1)
	{
		search_index = sorted_index;
		while (++search_index < size)
		{
			if (ft_strcmp(argv[sorted_index], argv[search_index]) > 0)
				swap_str(&argv[sorted_index], &argv[search_index]);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	sort_argv(argc, argv);
	print_argv(argc, argv);
	return (0);
}
