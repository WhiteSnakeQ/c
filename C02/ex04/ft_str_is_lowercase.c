/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:23:20 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 17:42:28 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < 'a' || str[i] > 'z'))
			return (0);
	}
	return (1);
}

int	main(void)
{
	char	*str;

	str = "helloworld";
	printf("%s - only lowcase %d\n", str, ft_str_is_lowercase(str));
	str = "51244214";
	printf("%s - only lowcase %d\n", str, ft_str_is_lowercase(str));
	str = "";
	printf("%s - only lowcase %d\n", str, ft_str_is_lowercase(str));
	str = "1245 33 12345";
	printf("%s - only lowcase %d\n", str, ft_str_is_lowercase(str));
}
