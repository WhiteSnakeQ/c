/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:09:30 by kreys             #+#    #+#             */
/*   Updated: 2025/07/20 01:13:46 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	str_len(char *str);

int	put_digit(char **result, int y, int x, char val)
{
	if (result[y][x] != '0' && result[y][x] != val)
		return (1);
	else
	{
		result[y][x] = val;
		return (0);
	}
}

int	check_up(char **result, int visibility, int size, int collum)
{
	int		i;
	char	max;

	i = -1;
	max = '0';
	while (++i < size)
	{
		if (result[i][collum] > max)
		{
			visibility--;
			max = result[i][collum];
		}
	}
	if (visibility == 0)
		return (0);
	else
		return (1);
}

int	check_down(char **result, int visibility, int size, int collum)
{
	int		i;
	char	max;

	i = -1;
	max = '0';
	while (++i < size)
	{
		if (result[str_len(result[0]) - 1 - i][collum] > max)
		{
			visibility--;
			max = result[str_len(result[0]) - 1 - i][collum];
		}
	}
	if (visibility == 0)
		return (0);
	else
		return (1);
}

int	check_left(char **result, int visibility, int size, int row)
{
	int		i;
	char	max;

	i = -1;
	max = '0';
	while (++i < size)
	{
		if (result[row][i] > max)
		{
			visibility--;
			max = result[row][i];
		}
	}
	if (visibility == 0)
		return (0);
	else
		return (1);
}

int	check_right(char **result, int visibility, int size, int row)
{
	int		i;
	char	max;

	i = -1;
	max = '0';
	while (++i < size)
	{
		if (result[row][str_len(result[0]) - 1 - i] > max)
		{
			visibility--;
			max = result[row][str_len(result[0]) - 1 - i];
		}
	}
	if (visibility == 0)
		return (0);
	else
		return (1);
}
