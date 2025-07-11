/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:34:24 by kreys             #+#    #+#             */
/*   Updated: 2025/07/10 19:25:26 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	get_type_char(char str)
{
	if (str >= '0' && str <= '9')
		return (3);
	else if (str >= 'A' && str <= 'Z')
		return (2);
	else if (str >= 'a' && str <= 'z')
		return (1);
	return (0);
}

void	make_world(char *str, int *i)
{
	int	first;

	first = 0;
	while (str && str[*i] && get_type_char(str[*i]))
	{
		if (first == 0 && get_type_char(str[*i]) == 1)
			str[*i] -= 32;
		else if (get_type_char(str[*i]) == 2 && first != 0)
			str[*i] += 32;
		*i += 1;
		first = 1;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (get_type_char(str[index]))
			make_world(str, &index);
		index++;
	}
	return (str);
}

int	main(void)
{
	{
	char	str[] = "helloworld r-r";
	
	printf("%s - before\n", str);
	printf("%s - after\n", ft_strcapitalize(str));
	}
	printf("\n");
	{
	char	str[] = "51244214";
	
	printf("%s - before\n", str);
	printf("%s - after\n", ft_strcapitalize(str));
	}
	printf("\n");
	{
	char	str[] = "";
	
	printf("%s - before\n", str);
	printf("%s - after\n", ft_strcapitalize(str));
	}
	printf("\n");
	{
	char	str[] = "BiGaLf";;
	
	printf("%s - before\n", str);
	printf("%s - after\n", ft_strcapitalize(str));
	}
	printf("\n");
	{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";;
	
	printf("%s - before\n", str);
	printf("%s - after\n", ft_strcapitalize(str));
	}
}
