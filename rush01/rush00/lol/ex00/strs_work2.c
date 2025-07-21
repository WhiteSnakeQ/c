/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_work2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:09:29 by kreys             #+#    #+#             */
/*   Updated: 2025/07/20 19:37:12 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

int	ft_sqrt(int nb);

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = -1;
	while (src[++index])
		dest[index] = src[index];
	dest[index] = '\0';
	return (dest);
}

char	*fill_str_increment(int size)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (ret);
	i = -1;
	while (++i < size)
		ret[i] = '1' + i;
	ret[i] = '\0';
	return (ret);
}

int	get_size_world(char *str)
{
	int	i;
	int	world;

	world = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			world++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if ((str[i] < 9 || str[i] > 13) && str[i] != 32 && str[i])
			return (-1);
	}
	return (ft_sqrt(world));
}
