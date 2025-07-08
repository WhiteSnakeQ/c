/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:18:44 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 17:40:04 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
			return (0);
	}
	return (1);
}

int	main(void)
{
	char	*str;

	str = "HelloWorld";
	printf("%s - only alpha %d\n", str, ft_str_is_alpha(str));
	str = "51244214";
	printf("%s - only alpha %d\n", str, ft_str_is_alpha(str));
	str = "";
	printf("%s - only alpha %d\n", str, ft_str_is_alpha(str));
	str = "look on this";
	printf("%s - only alpha %d\n", str, ft_str_is_alpha(str));
}
