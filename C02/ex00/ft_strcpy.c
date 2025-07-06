/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:03:07 by kreys             #+#    #+#             */
/*   Updated: 2025/07/01 20:14:50 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "stdio.h"

char *ft_strcpy(char *dest, char *src)
{
	int	index;

	index = -1;
	while (src[++index])
		dest[index] = src[index];
	dest[index] = '\0';

	return(dest);
}
