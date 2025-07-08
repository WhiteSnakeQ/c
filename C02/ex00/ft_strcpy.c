/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:03:07 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 17:18:42 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = -1;
	while (src[++index])
		dest[index] = src[index];
	dest[index] = '\0';
	return (dest);
}

int	main(void)
{
	char	dest1[50] = "dest";
	char	dest2[50] = "dest";
	char	src[50] = "hello world";

	printf("|%s| |%s| before\n", dest1, dest2);
	printf("|%s| |%s| after\n", ft_strcpy(dest1, src), strcpy(dest2, src));
	printf("|%s| |%s| dest\n", dest1, dest2);
	printf("\n\n");

	char	dest3[50] = "dest";
	char	dest4[50] = "dest";
	char	src1[50] = "";

	printf("|%s| |%s| before\n", dest3, dest4);
	printf("|%s| |%s| after\n", ft_strcpy(dest3, src1), strcpy(dest4, src1));
	printf("|%s| |%s| dest\n", dest3, dest4);
}
