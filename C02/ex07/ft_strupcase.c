/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:29:52 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 17:50:52 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

char	*ft_strupcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return (str);
}

int	main(void)
{
	
	{
	char	str[] = "helloworld";
	
	printf("%s - before\n", str);
	printf("%s - after\n", ft_strupcase(str));
	}
	printf("\n");
	{
	char	str[] = "51244214";
	
	printf("%s - before\n", str);
	printf("%s - after\n", ft_strupcase(str));
	}
	printf("\n");
	{
	char	str[] = "";
	
	printf("%s - before\n", str);
	printf("%s - after\n", ft_strupcase(str));
	}
	printf("\n");
	{
	char	str[] = "BiGaLf";;
	
	printf("%s - before\n", str);
	printf("%s - after\n", ft_strupcase(str));
	}
}
