/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 06:20:57 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 19:16:59 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	char	*str;

	str = "1234";
	printf("|%s| size(my) %d size(pc) %ld\n", str, ft_strlen(str), strlen(str));
	str = "";
	printf("|%s| size(my) %d size(pc) %ld\n", str, ft_strlen(str), strlen(str));
	str = "134235235235234";
	printf("|%s| size(my) %d size(pc) %ld\n", str, ft_strlen(str), strlen(str));
	str = "qweqwe e214 qwr qer";
	printf("|%s| size(my) %d size(pc) %ld\n", str, ft_strlen(str), strlen(str));
	str = "1";
	printf("|%s| size(my) %d size(pc) %ld\n", str, ft_strlen(str), strlen(str));
}
