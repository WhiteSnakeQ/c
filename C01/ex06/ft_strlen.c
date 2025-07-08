/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:21:12 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 17:03:14 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "stdio.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	char	*str;

	str = "Hello World";
	printf("|%s| - size(my func) %d | size(strlen) %ld\n", str, ft_strlen(str), strlen(str));
	str = "";
	printf("|%s| - size(my func) %d | size(strlen) %ld\n", str, ft_strlen(str), strlen(str));
	str = "12 + 4 + 20 = 36";
	printf("|%s| - size(my func) %d | size(strlen) %ld\n", str, ft_strlen(str), strlen(str));
}
