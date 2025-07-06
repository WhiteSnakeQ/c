/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 03:51:17 by kreys             #+#    #+#             */
/*   Updated: 2025/07/02 04:06:52 by kreys            ###   ########.fr       */
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
    while (src && src[++i] != '\0')
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

    return dest;
}

int	main(void)
{
	char	s1[20], s2[20];

	s1[0] = 'e';
	s1[1] = 'w';
	s1[2] = 'r';
	s1[3] = '\0';

	s2[0] = 'q';
	s2[1] = 'a';
	s2[2] = 'z';
	s2[3] = '\0';
	strcat(s1, s2);
	printf("%s - %s\n", s1, s2);
}