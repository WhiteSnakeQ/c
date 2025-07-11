/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:50:21 by kreys             #+#    #+#             */
/*   Updated: 2025/07/10 19:25:16 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"
#include <bsd/string.h>

unsigned int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	res;

	index = 0;
	res = str_len(src);
	if (size == 0)
		return (res);
	while (src[index] && index + 1 < size)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (res);
}

int	main(void)
{
	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	src[50] = "asdsa";
		int		i = 5;

		printf("|%s| |%s| before - int %d\n", dest, dest1, i);
		printf("|%s| |%s| after - result %d | %ld\n", dest, dest1, ft_strlcpy(dest, src, i), strlcpy(dest1, src, i));
	}
	printf("\n\n");
	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	src[50] = "hello World";
		int		i = 2;

		printf("|%s| |%s| before - int %d\n", dest, dest1, i);
		printf("|%s| |%s| after - result %d | %ld\n", dest, dest1, ft_strlcpy(dest, src, i), strlcpy(dest1, src, i));
	}
	printf("\n\n");
	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	src[50] = "";
		int		i = 12;

		printf("|%s| |%s| before - int %d\n", dest, dest1, i);
		printf("|%s| |%s| after - result %d | %ld\n", dest, dest1, ft_strlcpy(dest, src, i), strlcpy(dest1, src, i));
	}
	printf("\n\n");
	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	src[50] = "hello World";
		int		i = 12;

		printf("|%s| |%s| before - int %d\n", dest, dest1, i);
		printf("|%s| |%s| after - result %d | %ld\n", dest, dest1, ft_strlcpy(dest, src, i), strlcpy(dest1, src, i));
	}
	printf("\n\n");
	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	src[50] = "hello World";
		int		i = 0;

		printf("|%s| |%s| before - int %d\n", dest, dest1, i);
		printf("|%s| |%s| after - result %d | %ld\n", dest, dest1, ft_strlcpy(dest, src, i), strlcpy(dest1, src, i));
	}
	printf("\n\n");
	printf("\n\n");
	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	src[50] = "hello World";
		int		i = -1;

		printf("|%s| |%s| before - int %d\n", dest, dest1, i);
		printf("|%s| |%s| after - result %d | %ld\n", dest, dest1, ft_strlcpy(dest, src, i), strlcpy(dest1, src, i));
	}
	printf("\n\n");

	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	src[50] = "hello World";
		int		i = 7;

		printf("|%s| |%s| before - int %d\n", dest, dest1, i);
		printf("|%s| |%s| after - result %d | %ld\n", dest, dest1, ft_strlcpy(dest, src, i), strlcpy(dest1, src, i));
	}
	printf("\n\n");
	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	src[50] = "hello World";
		int		i = 12;

		printf("|%s| |%s| before - int %d\n", dest, dest1, i);
		printf("|%s| |%s| after - result %d | %ld\n", dest, dest1, ft_strlcpy(dest, src, i), strlcpy(dest1, src, i));
	}
	printf("\n\n");
}
