/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:43:12 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 19:56:51 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	fill_arr(char arr[10][10], int i, int b)
{
	i = -1;
	while (++i < 10)
	{
		b = -1;
		while (++b < 10)
			arr[i][b] = '-';
	}
}

int	print_arr(char arr[10][10], int *c_w)
{
	int	i;
	int	d;
	int	to_print;

	i = -1;
	while (++i < 10)
	{
		d = -1;
		while (++d < 10)
		{
			if (arr[d][i] == 'Q')
			{
				to_print = d + '0';
				write(1, &to_print, 1);
			}
		}
	}
	write(1, "\n", 1);
	*c_w += 1;
	return (-1);
}

int	fill_field(char arr[10][10], int row, int coll)
{
	int	i;
	int	d;

	i = 0;
	if (row > 9 || coll > 9)
		return (-1);
	while (i < 10)
	{
		if (arr[row][i] == 'Q')
			return (-1);
		if ((arr[i++][coll]) == 'Q')
			return (-1);
	}
	i = row;
	d = coll;
	while (i < 10 && i >= 0 && d < 10 && d >= 0)
		if (arr[i--][d--] == 'Q')
			return (-1);
	i = row;
	d = coll;
	while (i < 10 && i >= 0 && d < 10 && d >= 0)
		if (arr[i++][d--] == 'Q')
			return (-1);
	arr[row][coll] = 'Q';
	return (0);
}

int	build_all(int start_i, int start_b, char arr[10][10], int *count_win)
{
	int		start_ii;
	int		start_bb;
	int		cc;

	cc = fill_field(arr, start_i, start_b++);
	if (cc == -1)
		return (-1);
	start_ii = start_i;
	start_bb = start_b - 1;
	if (start_b == 10)
	{
		cc = print_arr(arr, count_win);
		arr[start_ii][start_bb] = '-';
		return (cc);
	}
	start_i = -1;
	while (cc != 1 && start_ii > ++start_i)
		cc = build_all(start_i, start_b, arr, count_win);
	start_i = start_ii;
	while (cc != 1 && ++start_i <= 9)
		cc = build_all(start_i, start_b, arr, count_win);
	if (cc == -1)
		arr[start_ii][start_bb] = '-';
	return (cc);
}

int	ft_ten_queens_puzzle(void)
{
	int		start_i;
	int		start_b;
	int		count_win;
	char	arr[10][10];

	count_win = 0;
	start_b = 0;
	start_i = -1;
	fill_arr(arr, 0, 0);
	while (++start_i < 10)
		build_all(start_i, start_b, arr, &count_win);
	return (count_win);
}

int	main(void)
{
	printf("all comb - %d\n", ft_ten_queens_puzzle());
}
