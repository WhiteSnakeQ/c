/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:15:49 by kreys             #+#    #+#             */
/*   Updated: 2025/07/01 20:17:52 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "stdio.h"

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	index;

	index = -1;
	while (src[++index] && n > index)
		dest[index] = src[index];
	while (n > index)
			dest[index++] = '\0';
	return(dest);
}