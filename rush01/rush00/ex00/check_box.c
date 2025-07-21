/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:09:21 by kreys             #+#    #+#             */
/*   Updated: 2025/07/20 01:13:58 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_up(char **result, int visibility, int size, int collum);
int		check_down(char **result, int visibility, int size, int collum);
int		check_left(char **result, int visibility, int size, int row);
int		check_right(char **result, int visibility, int size, int row);
int		str_len(char *str);

int	check_vertcal(char *result, int size)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (result[i] == result[j])
				return (1);
		}
	}
	return (0);
}

int	check_hotizonta(char **result, int size, int collum)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (result[i][collum] == result[j][collum])
				return (1);
		}
	}
	return (0);
}

int	check_same_lines(char **result, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (check_vertcal(result[i], size))
			return (1);
	}
	i = -1;
	while (++i < size)
	{
		if (check_hotizonta(result, size, i))
			return (1);
	}
	return (0);
}

int	check_all(char **result, char **tab)
{
	int	i;
	int	size;

	size = str_len(result[0]);
	i = -1;
	while (++i < size)
	{
		if (check_up(result, tab[0][i] - '0', size, i))
			return (1);
		if (check_down(result, tab[1][i] - '0', size, i))
			return (1);
		if (check_left(result, tab[2][i] - '0', size, i))
			return (1);
		if (check_right(result, tab[3][i] - '0', size, i))
			return (1);
	}
	if (check_same_lines(result, size))
		return (1);
	return (0);
}
