/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 03:51:17 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 18:29:58 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char *ft_strcat(char *dest, char *src)
{
	int dest_len;
    int i;

	i = -1;
	dest_len = str_len(dest);
    while (src[++i])
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
    return dest;
}

int	main(void)
{
	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "hello world";

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strcat(dest1, src), strcat(dest2, src));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "h";

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strcat(dest1, src), strcat(dest2, src));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}
	{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "";

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strcat(dest1, src), strcat(dest2, src));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "";
	char	dest2[50] = "";
	char	src[50] = "hello world";

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strcat(dest1, src), strcat(dest2, src));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}

	{
	char	dest1[50] = "";
	char	dest2[50] = "";
	char	src[50] = "";

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strcat(dest1, src), strcat(dest2, src));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");
	}
}