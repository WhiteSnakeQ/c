/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:38:54 by kreys             #+#    #+#             */
/*   Updated: 2025/07/12 16:51:14 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	rush(int x, int y);
void	rush00(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);

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

void	select_rush(char **argv)
{
	int	x;
	int	y;
	int	rush_m;

	rush_m = ft_atoi(argv[3]);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (rush_m == 0)
		rush00(x, y);
	if (rush_m == 1)
		rush(x, y);
	if (rush_m == 2)
		rush02(x, y);
	if (rush_m == 3)
		rush03(x, y);
	if (rush_m == 4)
		rush04(x, y);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	else if (argc == 4)
		select_rush(argv);
}
