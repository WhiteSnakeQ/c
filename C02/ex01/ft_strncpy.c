/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:15:49 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 17:25:28 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (src[index] && n > index)
	{
		dest[index] = src[index];
		index++;
	}
	while (n > index)
		dest[index++] = '\0';
	return (dest);
}

int	main(void)
{
	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "hello world";
	int		i = 5;

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after | size - %d\n", ft_strncpy(dest1, src, i), strncpy(dest2, src, i), i);
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "";
	int		i = 5;

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after | size - %d\n", ft_strncpy(dest1, src, i), strncpy(dest2, src, i), i);
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "hello world";
	int		i = 0;

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after | size - %d\n", ft_strncpy(dest1, src, i), strncpy(dest2, src, i), i);
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "hello world";
	int		i = 1;

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after | size - %d\n", ft_strncpy(dest1, src, i), strncpy(dest2, src, i), i);
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "";
	int		i = 0;

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after | size - %d\n", ft_strncpy(dest1, src, i), strncpy(dest2, src, i), i);
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "hello world";
	int		i = 50;

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after | size - %d\n", ft_strncpy(dest1, src, i), strncpy(dest2, src, i), i);
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}
}
