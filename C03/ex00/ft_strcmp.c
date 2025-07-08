/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 03:51:17 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 18:24:11 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

int ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char	*str1, *str2;

	str1 = "lelele";
	str2 = "lelele";
	printf("%d | %d \n\n",ft_strcmp(str1, str2), strcmp(str1, str2));
	
	str1 = "lelel";
	str2 = "lelele";
	printf("%d | %d \n\n",ft_strcmp(str1, str2), strcmp(str1, str2));

	str1 = "lelele";
	str2 = "lelel";
	printf("%d | %d \n\n",ft_strcmp(str1, str2), strcmp(str1, str2));

	str1 = "";
	str2 = "lelele";
	printf("%d | %d \n\n",ft_strcmp(str1, str2), strcmp(str1, str2));

	str1 = "lelele";
	str2 = "";
	printf("%d | %d \n\n",ft_strcmp(str1, str2), strcmp(str1, str2));

	str1 = "";
	str2 = "";
	printf("%d | %d \n\n",ft_strcmp(str1, str2), strcmp(str1, str2));
}
