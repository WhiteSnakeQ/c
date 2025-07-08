/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:23:20 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 17:41:10 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
	}
	return (1);
}

int	main(void)
{
		char	*str;

	str = "HelloWorld";
	printf("%s - only numeric %d\n", str, ft_str_is_numeric(str));
	str = "51244214";
	printf("%s - only numeric %d\n", str, ft_str_is_numeric(str));
	str = "";
	printf("%s - only numeric %d\n", str, ft_str_is_numeric(str));
	str = "1245 33 12345";
	printf("%s - only numeric %d\n", str, ft_str_is_numeric(str));
}
