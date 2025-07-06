/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 03:45:02 by kreys             #+#    #+#             */
/*   Updated: 2025/07/05 03:49:50 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_strs_to_tab.h"
#include "stdio.h"
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		write(1, &str[i++], 1);
}

void ft_putnbr(int nb)
{
	long	numb;
	int		to_write;

	numb = nb;
	if (nb < 0)
	{
		numb = -numb;
		write(1, "-", 1);
	}
	if (numb >= 10)
		ft_putnbr(numb / 10);
	to_write = '0' + numb % 10;
	write(1, &to_write, 1);
}

void ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par && par[++i].str)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
	}
}
