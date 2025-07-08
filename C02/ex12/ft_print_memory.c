/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 01:37:24 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 14:39:58 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"

#define BINARYSIZE 256
#define LINESIZE 16
#define HEXTAB "0123456789abcdef"
#define BASESIZE 16

void	put_hex_char(unsigned long dec, int digit)
{
	if (digit == 0 && dec < 16)
		write(1, "0", 1);
	if (dec >= 16)
		put_hex_char(dec / 16, digit + 1);
	write(1, &HEXTAB[dec % BASESIZE], 1);
}

void	put_address(char *str)
{
	int	byt_shift;

	byt_shift = 64;
	while (byt_shift > 0)
	{
		byt_shift -= 8;
		put_hex_char(((unsigned long)str >> byt_shift) % BINARYSIZE, 0);
	}
	write(1, ": ", 2);
}

void	put_hex_values(char *str, int size)
{
	int	i;

	i = 0;
	while (size > i && i < LINESIZE)
	{
		put_hex_char((unsigned char)str[i], 0);
		if (i++ % 2 == 1)
			write(1, " ", 1);
	}
	while (i < LINESIZE)
	{
		write(1, "  ", 2);
		if (i++ % 2 == 1)
			write(1, " ", 1);
	}
}

void	put_text(char *str, int size)
{
	int	i;

	i = 0;
	while (size > i && i < LINESIZE)
	{
		if (str[i] < 32 || str[i] == 127)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*str;

	str = (char *)addr;
	while (size > 0)
	{
		put_address(str);
		put_hex_values(str, size);
		put_text(str, size);
		if (size < 16)
			break ;
		size -= LINESIZE;
		str += LINESIZE;
	}
	return (addr);
}
