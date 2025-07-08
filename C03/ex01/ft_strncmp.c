/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 03:51:17 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 18:27:48 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && n > i + 1)
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
	int		i;

	i = 5;
	str1 = "lelele";
	str2 = "lelele";
	printf("%d | %d \n\n",ft_strncmp(str1, str2, i), strncmp(str1, str2, i));
	
	str1 = "lelel";
	str2 = "lelele";
	printf("%d | %d \n\n",ft_strncmp(str1, str2, i), strncmp(str1, str2, i));

	str1 = "lelele";
	str2 = "lelel";
	printf("%d | %d \n\n",ft_strncmp(str1, str2, i), strncmp(str1, str2, i));

	str1 = "";
	str2 = "lelele";
	printf("%d | %d \n\n",ft_strncmp(str1, str2, i), strncmp(str1, str2, i));

	str1 = "lelele";
	str2 = "";
	printf("%d | %d \n\n",ft_strncmp(str1, str2, i), strncmp(str1, str2, i));

	str1 = "";
	str2 = "";
	printf("%d | %d \n\n",ft_strncmp(str1, str2, i), strncmp(str1, str2, i));
}
