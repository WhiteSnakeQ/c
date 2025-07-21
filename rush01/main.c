#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "stdlib.h"

void	fill_str(char *str, char to_fill, int size)
{
	int	i;

	i = -1;
	while (size > ++i)
		str[i] = to_fill;
}

void	fill_strs(char **tab, char to_fill, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		fill_str(tab[i], to_fill, size);
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


char	**part1(int size)
{
	char	**tab;

	tab = create_strs(size);
	// strcpy(tab[0], "4321");
	// strcpy(tab[1], "1222");
	// strcpy(tab[2], "4321");
	// strcpy(tab[3], "1222");
	strcpy(tab[0], "4122");
	strcpy(tab[1], "1332");
	strcpy(tab[2], "2321");
	strcpy(tab[3], "3212");
	return (tab);
}

int	get_size(void)
{
	return (4);
}

int	put_val(char *c, char val)
{
	if (*c != '0' && *c != val)
		return (1);
	*c = val;
	return (0);
}

int	fill_up_max(char **strs, int size, int collum)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (put_val(&strs[i][collum], i + '1'))
			return (1);
	}
	return (0);
}

int	fill_down_max(char **strs, int size, int collum)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (put_val(&strs[size - i - 1][collum], i + '1'))
			return (1);
	}
	return (0);
}

int	fill_left_max(char **strs, int size, int collum)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (put_val(&strs[collum][i], i + '1'))
			return (1);
	}
	return (0);
}

int	fill_right_max(char **strs, int size, int collum)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (put_val(&strs[collum][size - i - 1], i + '1'))
			return (1);
	}
	return (0);
}

int	fill_min_max(char **strs, char **tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (tab[0][i] == size + '0')
		{
			if (fill_up_max(strs, size, i))
				return (1);
		}
		else if (tab[0][i] == '1')
		{
			if (put_val(&strs[0][i], size + '0'))
				return (1);
		}
	}
	i = -1;
	while (++i < size)
	{
		if (tab[1][i] == size + '0')
		{
			if (fill_down_max(strs, size, i))
				return (1);
		}
		else if (tab[1][i] == '1')
		{
			if (put_val(&strs[size - 1][i], size + '0'))
				return (1);
		}
	}
	i = -1;
	while (++i < size)
	{
		if (tab[2][i] == size + '0')
		{
			if (fill_left_max(strs, size, i))
				return (1);
		}
		else if (tab[2][i] == '1')
		{
			if (put_val(&strs[i][0], size + '0'))
				return (1);
		}
	}
	i = -1;
	while (++i < size)
	{
		if (tab[3][i] == size + '0')
		{
			if (fill_right_max(strs, size, i))
				return (1);
		}
		else if (tab[3][i] == '1')
		{
			if (put_val(&strs[i][size - 1], size + '0'))
				return (1);
		}
	}
	return (0);
}

int	fill_two_with_one(char **strs, char **tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (tab[0][i] == '2' && strs[0][i] != '0')
		{
			if (put_val(&strs[1][i], size + '0'))
				return (1);
		}
		if (tab[1][i] == '2' && strs[size - 1][i] != '0')
		{
			if (put_val(&strs[size - 2][i], size + '0'))
				return (1);
		}
		if (tab[2][i] == '2' && strs[i][0] != '0')
		{
			if (put_val(&strs[i][1], size + '0'))
				return (1);
		}
		if (tab[3][i] == '2' && strs[size - 1][i] != '0')
		{
			if (put_val(&strs[i][size - 2], size + '0'))
				return (1);
		}
	}
	
}

int	fill_max_n(char **strs, char **tab, int size)
{
	int	i;
	int	j;
	int	q;

	i = -1;
	while (++i < size)
	{
		j = -1;
		q = 0;
		if (tab[0][i] == size + '0' - 1)
		{
			if (strs[0][i] != '0')
				q = 1;
			while (++j < size - 1)
			{
				if (put_val(&strs[j][i], '1' + j + q))
					return (1);
			}			
		}
		j = -1;
		q = 0;
		if (tab[1][i] == size + '0' - 1 && strs[size - 1][i] != '0')
		{
			if (strs[size - 1][i] != '0')
				q = 1;
			while (++j < size - 1)
			{
				if (put_val(&strs[j - 1 - i][i], '1' + j + q))
					return (1);
			}		
		}
		j = -1;
		q = 0;
		if (tab[2][i] == size + '0' - 1 && strs[i][0] != '0')
		{
			if (strs[i][0] != '0')
				q = 1;
			while (++j < size - 1)
			{
				if (put_val(&strs[i][j], '1' + j + q))
					return (1);
			}	
		}
		j = -1;
		q = 0;
		if (tab[3][i] == size + '0' - 1 && strs[size - 1][i] != '0')
		{
			if (strs[i][size - 1] != '0')
				q = 1;
			while (++j < size - 1)
			{
				if (put_val(&strs[i][j - 1 - i], '1' + j + q))
					return (1);
			}	
		}
	}
	
}

int	put_biggest_left_up_down(char **strs, int y, int x, int size)
{
	int	j;
	int	i;

	j = size + 1;
	while (--j > 0)
	{
		i = -1;
		while (++i < size)
		{
			if (strs[i][x] == '0' + j)
				break ;
		}
		if (i == size)
		{
			if (put_val(&strs[y][x], j + '0'))
				return (1);
			else
				return (0);
		}
	}
	return (1);
}

int	put_biggest_left_rigt(char **strs, int y, int x, int size)
{
	int	j;
	int	i;

	j = size + 1;
	while (--j > 0)
	{
		i = -1;
		while (++i < size)
		{
			if (strs[y][i] == '0' + j)
				break ;
		}
		if (i == size)
		{
			if (put_val(&strs[y][x], j + '0'))
				return (1);
			else
				return (0);
		}	
	}
	return (1);
}

int	put_some(char **strs, char **tab, int size, int tab_i)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		if (tab[0][i] == tab_i + '0' && strs[tab_i][i] == size + '0')
		{
			if (put_biggest_left_up_down(strs, 0, i, size))
				return (0);
		}
		if (tab[1][i] == tab_i + '0' && strs[size - tab_i - 1][i] == size + '0')
		{
			if (put_biggest_left_up_down(strs, size - 1, i, size))
				return (0);
		}

		if (tab[2][i] == tab_i + '0' && strs[i][tab_i] == size + '0')
		{
			if (put_biggest_left_rigt(strs, i, 0, size))
				return (0);
		}
		if (tab[3][i] == tab_i + '0' && strs[i][size - tab_i - 1] == size + '0')
		{
			if (put_biggest_left_rigt(strs, i, size - 1, size))
				return (0);
		}
	}
	return (1);
}

int	fill_recursive(char **strs, char **tab, int size)
{
	int	i;

	i = 1;
	while (++i < size - 1)
	{
		put_some(strs, tab, size, i);
	}
}

int	check_hor(char **result, int row, char val, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (result[row][i] == val)
			return (1);
	}
	return (0);
}

int	put_and_check_up(char **strs, int y, int x, int size)
{
	int	j;
	int	i;

	j = size + 1;
	while (--j > 0)
	{
		i = -1;
		while (++i < size)
		{
			if (strs[i][x] == '0' + j)
				break ;
		}
		if (i == size)
		{
			if (check_hor(strs, y, j + '0', size))
				continue ;
			if (put_val(&strs[y][x], j + '0'))
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

int	check_ver(char **result, int collum, char val, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (result[i][collum] == val)
			return (1);
	}
	return (0);
}

int	put_and_check_hor(char **strs, int y, int x, int size)
{
	int	j;
	int	i;

	j = size + 1;
	while (--j > 0)
	{
		i = -1;
		while (++i < size)
		{
			if (strs[y][i] == '0' + j)
				break ;
		}
		if (i == size)
		{
			if (check_ver(strs, x, j + '0', size))
				continue ;
			if (put_val(&strs[y][x], j + '0'))
				return (1);
			else
				return (0);
		}	
	}
	return (0);
}


int	fill_vert(char **result, char **tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (result[j][i] == '0' && put_and_check_up(result, j, i, size))
				return (1);
		}
	}
	
}

int	fill_hor(char **result, char **tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (result[i][j] == '0' && put_and_check_hor(result, j, i, size))
				return (1);
		}
	}
	
}

int	fill_full(char **result, char **tab, int size)
{
	fill_vert(result, tab, size);
	fill_hor(result, tab, size);
	fill_vert(result, tab, size);
	fill_hor(result, tab, size);
}

char	**part2(char **tab, int size)
{
	char	**result;

	result = create_strs(size);
	if (!result)
		return (result);
	fill_strs(result, '0', size);
	fill_min_max(result, tab, size);
	fill_two_with_one(result, tab, size);
	fill_max_n(result, tab, size);
	fill_recursive(result, tab, size);
	fill_full(result, tab, size);
	return (result);
}

int	main(void)
{
	char	**tab;
	char	**result;
	int		size;

	size = get_size();
	tab = part1(size);
	result = part2(tab, size);
	if (!result)
		write(1, "Error\n", 6);
	else
	{
		print_strs(result);
		free_strs(result);
	}
	free_strs(tab);
}
