/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 06:29:08 by kreys             #+#    #+#             */
/*   Updated: 2025/07/06 09:39:15 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_tail.h"
#include "stdio.h"
#include "stdlib.h"

long	convert_str_to_int(char	*str)
{
	int		i;
	long	numb;

	i = -1;
	numb = 0;
	while (str && str[++i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			numb = (numb * 10) + (str[i] - '0');
		else
			break ;
	}
	return (numb);
}

int	ft_atoi(char *str)
{
	int		i;
	int		positive;
	long	res;

	positive = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			positive = -positive;
		i++;
	}
	res = convert_str_to_int(&str[i]);
	if (positive < 0)
		res = -res;
	return (res);
}
