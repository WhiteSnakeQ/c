/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 07:19:41 by kreys             #+#    #+#             */
/*   Updated: 2025/07/06 10:46:36 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_tail.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	is_numbr(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	put_str(char *str, int fd, int size)
{
	int	i;

	if (size < 0)
	{
		i = 0;
		while (str && str[i])
			i++;
		write(fd, str, i);
	}
	else
		write(fd, str, size);
}
