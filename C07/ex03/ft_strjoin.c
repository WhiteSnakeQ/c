/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 05:57:08 by kreys             #+#    #+#             */
/*   Updated: 2025/07/09 22:08:29 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	i = -1;
	dest_len = str_len(dest);
	while (src && src[++i])
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}

int	strs_len(char **strs, int size)
{
	int	i;
	int	str_l;

	i = -1;
	str_l = 0;
	while (size > ++i)
		str_l += str_len(strs[i]);
	return (str_l);
}

char	*create_str(int size)
{
	char	*str;
	int		i;

	str = malloc((size  + 1) * sizeof(char));
	i = -1;
	while (str && ++i < size)
		str[i] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res_str;
	int		strs_l;
	int		i;

	i = -1;
	if (size <= 0)
	{
		res_str = malloc(sizeof(char *));
		res_str[0] = '\0';
		return (res_str);
	}
	strs_l = strs_len(strs, size) + (str_len(sep) * (size - 1));
	res_str = create_str(strs_l);
	while (++i < size)
	{
		ft_strcat(res_str, strs[i]);
		if (i + 1 < size)
			ft_strcat(res_str, sep);
	}
	return (res_str);
}

int	main(int argc, char **argv)
{
	char	*str;

	if (argc < 3)
		return (0);
	printf("Size - %d\n", argc - 2);
	printf("Sep - %s\n", argv[1]);
	str = ft_strjoin(argc - 2, &argv[2], argv[1]);
	printf("%s\n", str);
	free(str);
	return (0);
}