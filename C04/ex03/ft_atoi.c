/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 06:29:08 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 19:33:56 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_atoi(char *str)
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

int	main(void)
{
	{
		char	*str = "123a456";
		printf("%s  : %d\n", str, ft_atoi(str));
		printf("\n");
	}

	{
		char	*str = "a123";
		printf("%s  : %d\n", str, ft_atoi(str));
		printf("\n");
	}

	{
		char	*str = " 123a456";
		printf("%s  : %d\n", str, ft_atoi(str));
		printf("\n");
	}

	{
		char	*str = "-+123";
		printf("%s  : %d\n", str, ft_atoi(str));
		printf("\n");
	}

	{
		char	*str = "+-123";
		printf("%s  : %d\n", str, ft_atoi(str));
		printf("\n");
	}

	{
		char	*str = "2147483647";
		printf("%s  : %d\n", str, ft_atoi(str));
		printf("\n");
	}

	{
		char	*str = "-2147483648";
		printf("%s  : %d\n", str, ft_atoi(str));
		printf("\n");
	}

	{
		char	*str = "2147483648";
		printf("%s  : %d\n", str, ft_atoi(str));
		printf("\n");
	}

	{
		char	*str = "-2147483649 str,";
		printf("%s  : %d\n", str, ft_atoi(str));
		printf("\n");
	}

	{
		char	*str = "";
		printf("%s  : %d\n", str, ft_atoi(str));
		printf("\n");
	}
}
