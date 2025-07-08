/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 04:24:31 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 19:13:44 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"
#include <bsd/string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	size_dest;
	unsigned int	size_src;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	i = 0;
	if (size_dest < size)
		size_src += size_dest;
	else
		size_src += size;
	while (src[i] && size > i + (size_dest + 1))
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_src);
}

int	main(void)
{
	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	*src = "sda";
		int		i = 4;

		printf("dest - %s | i = %d\n", dest, i);
		printf("%s %d\n%s %ld\n", dest, ft_strlcat(dest, src, i), dest1, strlcat(dest1, src, i));
		printf("\n\n");
	}

	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	*src = "sda";
		int		i = 9;

		printf("dest - %s | i = %d\n", dest, i);
		printf("%s %d\n%s %ld\n", dest, ft_strlcat(dest, src, i), dest1, strlcat(dest1, src, i));
		printf("\n\n");
	}

	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	*src = "hello world";
		int		i = 9;

		printf("dest - %s | i = %d\n", dest, i);
		printf("%s %d\n%s %ld\n", dest, ft_strlcat(dest, src, i), dest1, strlcat(dest1, src, i));
		printf("\n\n");
	}

	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	*src = "hello world";
		int		i = 0;

		printf("dest - %s | i = %d\n", dest, i);
		printf("%s %d\n%s %ld\n", dest, ft_strlcat(dest, src, i), dest1, strlcat(dest1, src, i));
		printf("\n\n");
	}

	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	*src = "hello world";
		int		i = 27;

		printf("dest - %s | i = %d\n", dest, i);
		printf("%s %d\n%s %ld\n", dest, ft_strlcat(dest, src, i), dest1, strlcat(dest1, src, i));
		printf("\n\n");
	}

	{
		char	dest[50] = "dest";
		char	dest1[50] = "dest";
		char	*src = "";
		int		i = 27;

		printf("dest - %s | i = %d\n", dest, i);
		printf("%s %d\n%s %ld\n", dest, ft_strlcat(dest, src, i), dest1, strlcat(dest1, src, i));
		printf("\n\n");
	}

	{
		char	dest[50] = "";
		char	dest1[50] = "";
		char	*src = "q12w";
		int		i = 27;

		printf("dest - %s | i = %d\n", dest, i);
		printf("%s %d\n%s %ld\n", dest, ft_strlcat(dest, src, i), dest1, strlcat(dest1, src, i));
		printf("\n\n");
	}

	{
		char	dest[50] = "";
		char	dest1[50] = "";
		char	*src = "";
		int		i = 27;

		printf("dest - %s | i = %d\n", dest, i);
		printf("%s %d\n%s %ld\n", dest, ft_strlcat(dest, src, i), dest1, strlcat(dest1, src, i));
		printf("\n\n");
	}

	{
		char	dest[50] = "f";
		char	dest1[50] = "f";
		char	*src = "f";
		int		i = 0;

		printf("dest - %s | i = %d\n", dest, i);
		printf("%s %d\n%s %ld\n", dest, ft_strlcat(dest, src, i), dest1, strlcat(dest1, src, i));
		printf("\n\n");
	}

	{
		char	dest[50] = "f";
		char	dest1[50] = "f";
		char	*src = "f";
		int		i = 2;

		printf("dest - %s | i = %d\n", dest, i);
		printf("%s %d\n%s %ld\n", dest, ft_strlcat(dest, src, i), dest1, strlcat(dest1, src, i));
		printf("\n\n");
	}
}
