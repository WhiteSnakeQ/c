/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:23:20 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 17:45:05 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_str_is_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= 32 && str[i] < 126))
			return (0);
	}
	return (1);
}

int	main(void)
{
	char	*str;

	str = "helloworld";
	printf("%s - only printable %d\n", str, ft_str_is_printable(str));
	str = "51\b244214";
	printf("%s - only printable %d\n", str, ft_str_is_printable(str));
	str = "";
	printf("%s - only printable %d\n", str, ft_str_is_printable(str));
	str = "BIG\nALF";
	printf("%s - only printable %d\n", str, ft_str_is_printable(str));
}