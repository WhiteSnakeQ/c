/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exwe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 08:39:28 by agaliste          #+#    #+#             */
/*   Updated: 2025/07/01 04:48:48 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(STDOUT_FILENO, &c, 1);
}

void    comb(int start, int n)
{
    int i;

    if (n == 0)
    {
        ft_putchar(',');
        ft_putchar(' ');
        return ;
    }
    i = start + 1;
    while (i < 10)
    {
        ft_putchar(start + '0');
        ft_putchar(i + '0');
        comb(i, n - 1);
        i++;
    }
}

void	ft_print_combn(int n)
{
    comb(0, n);
}

void main(void)
{
	ft_print_combn(1);
}