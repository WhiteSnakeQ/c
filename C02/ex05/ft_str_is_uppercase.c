/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:23:20 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 17:43:13 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < 'A' || str[i] > 'Z'))
			return (0);
	}
	return (1);
}

int	main(void)
{
	char	*str;

	str = "helloworld";
	printf("%s - only uppercase %d\n", str, ft_str_is_uppercase(str));
	str = "51244214";
	printf("%s - only uppercase %d\n", str, ft_str_is_uppercase(str));
	str = "";
	printf("%s - only uppercase %d\n", str, ft_str_is_uppercase(str));
	str = "BIGALF";
	printf("%s - only uppercase %d\n", str, ft_str_is_uppercase(str));
}
