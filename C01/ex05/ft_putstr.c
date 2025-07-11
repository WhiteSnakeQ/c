/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:17:45 by kreys             #+#    #+#             */
/*   Updated: 2025/07/10 19:19:27 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, str_len(str));
}

int	main(void)
{
	ft_putstr("Hello world\n");
	ft_putstr("\n");
	ft_putstr("");
	ft_putstr("12 + 4");
	ft_putstr("\n");
}
