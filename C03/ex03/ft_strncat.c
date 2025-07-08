/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 03:51:17 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 18:36:09 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
    unsigned int	i;

	i = 0;
	dest_len = str_len(dest);
    while (src[i] != '\0' && nb > i)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
    return dest;
}

int	main(void)
{
	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "hello world";
	int		i = 10;

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strncat(dest1, src, i), strncat(dest2, src, i));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "h";
	int		i = 1;

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strncat(dest1, src, i), strncat(dest2, src, i));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}
	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "";
	int		i = 5;

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strncat(dest1, src, i), strncat(dest2, src, i));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "";
	char	dest2[50] = "";
	char	src[50] = "hello world";
	int		i = 5;

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strncat(dest1, src, i), strncat(dest2, src, i));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "";
	char	dest2[50] = "";
	char	src[50] = "";
	int		i = 5;
	
	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strncat(dest1, src, i), strncat(dest2, src, i));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}
}