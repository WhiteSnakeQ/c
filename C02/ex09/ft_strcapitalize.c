/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:34:24 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 14:46:05 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		else if (get_type_char(str[*i]) == 2)
			str[*i] += 32;
		*i += 1;
		first = 1;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	while (str && str[index])
	{
		if (get_type_char(str[index]))
			make_world(str, &index);
		index++;
	}
	return (str);
}
