/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 05:20:30 by kreys             #+#    #+#             */
/*   Updated: 2025/07/09 21:59:53 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int		size;
	int		i;
	char	*dup;

	i = -1;
	size = str_len(src);
	dup = malloc((size + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[size] = '\0';
	while (++i < size)
		dup[i] = src[i];
	return (dup);
}

int	main(void)
{
	char	*str;

	str = ft_strdup("l");
	printf("%s\n", str);
	free(str);

	str = ft_strdup("124310942805823");
	printf("%s\n", str);
	free(str);

	str = ft_strdup("");
	printf("%s\n", str);
	free(str);
}
