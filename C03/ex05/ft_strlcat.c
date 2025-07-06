/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 04:24:31 by kreys             #+#    #+#             */
/*   Updated: 2025/07/02 05:06:11 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"
#include <bsd/string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return(i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	size_dest;
	int	size_src;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	i = -1;
	if (size_dest < size)
		size_src += size_dest;
	else
		size_src += size;
	while (dest && dest[++i] && size > i + (size_dest + 1))
		dest[size_dest + i] = src[i];
	dest[size_dest + i] = '\0';
	return (size_src);
}

int	main(void)
{
	char	s1[40];
	char	s2[40];

	s1[0] = 'e';
	s1[1] = 'w';
	s1[2] = 'r';
	s1[3] = '\0';

	s2[0] = 'q';
	s2[1] = 'a';
	s2[2] = 'z';
	s2[3] = '\0';


	printf("%d\n%s\n%s\n",	ft_strlcat(s1, s2, 1), s1,s2);
}