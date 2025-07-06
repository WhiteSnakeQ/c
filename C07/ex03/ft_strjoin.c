/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 05:57:08 by kreys             #+#    #+#             */
/*   Updated: 2025/07/04 06:24:55 by kreys            ###   ########.fr       */
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
	while (src && src[++i] != '\0')
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

	str = malloc((size * sizeof(char)) + sizeof(char));
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
	if (!strs || !*strs || size <= 0)
	{
		res_str = malloc(sizeof(char));
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

int	main(void)
{
	char	*strs[5];

	strs[0] = "qwer";
	strs[1] = "qwesfsefsefr";
	strs[2] = "\0";
	
	char	*str;
	str = ft_strjoin(2, strs, " , ");
	printf("%s\n", str);
	free(str);
}