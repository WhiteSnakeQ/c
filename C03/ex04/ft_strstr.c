/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 04:12:37 by kreys             #+#    #+#             */
/*   Updated: 2025/07/02 04:24:39 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return(i);
}

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if (s1[i] != s2[i])
			return(s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char *ft_strstr(char *str, char *to_find)
{
	int	i;
	int	size_str_find;

	size_str_find = ft_strlen(to_find);
	i = 0;
	while (str[i] && to_find)
	{
		if (!ft_strncmp(&str[i], to_find, size_str_find))
			return (&str[i]);
		i++;
	}
	return ((void *)0);
}

int	main(void)
{
	char	*s1, *s2;

	s1 = "asdasdasdasdasdlol3242342";
	s2 = "";
	printf("%s\n%s\n", ft_strstr(s1, s2), strstr(s1, s2));
}
