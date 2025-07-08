/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 04:12:37 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 18:45:24 by kreys            ###   ########.fr       */
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

char *ft_strstr(char *str, char *to_find)
{
	int	i;
	int	size_str_find;

	size_str_find = ft_strlen(to_find);
	i = 0;
	if (!*to_find)
		return (str);
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
	char	*str1, *to_find;

	str1 = "0123456789";
	to_find = "5";
	printf("%s str \n%s to_find\n", str1, to_find);
	printf("%s \n%s\n", ft_strstr(str1, to_find), strstr(str1, to_find));
	printf("\n");
	
	str1 = "0123456789";
	to_find = "123";
	printf("%s str \n%s to_find\n", str1, to_find);
	printf("%s \n%s\n", ft_strstr(str1, to_find), strstr(str1, to_find));
	printf("\n");

	str1 = "0123456789";
	to_find = "8";
	printf("%s str \n%s to_find\n", str1, to_find);
	printf("%s \n%s\n", ft_strstr(str1, to_find), strstr(str1, to_find));
	printf("\n");

	str1 = "0123456789";
	to_find = "";
	printf("%s str \n%s to_find\n", str1, to_find);
	printf("%s \n%s\n", ft_strstr(str1, to_find), strstr(str1, to_find));
	printf("\n");

	str1 = "";
	to_find = "123";
	printf("%s str \n%s to_find\n", str1, to_find);
	printf("%s \n%s\n", ft_strstr(str1, to_find), strstr(str1, to_find));
	printf("\n");

	str1 = "";
	to_find = "";
	printf("%s str \n%s to_find\n", str1, to_find);
	printf("%s \n%s\n", ft_strstr(str1, to_find), strstr(str1, to_find));
	printf("\n");

	str1 = "0123456789";
	to_find = "iuo";
	printf("%s str \n%s to_find\n", str1, to_find);
	printf("%s \n%s\n", ft_strstr(str1, to_find), strstr(str1, to_find));
	printf("\n");

	str1 = "123";
	to_find = "1234";
	printf("%s str \n%s to_find\n", str1, to_find);
	printf("%s \n%s\n", ft_strstr(str1, to_find), strstr(str1, to_find));
	printf("\n");

	str1 = "";
	to_find = "iuo";
	printf("%s str \n%s to_find\n", str1, to_find);
	printf("%s \n%s\n", ft_strstr(str1, to_find), strstr(str1, to_find));
	printf("\n");
}