/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 01:37:24 by kreys             #+#    #+#             */
/*   Updated: 2025/07/02 03:35:31 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"

void	conv_dec_to_hex(unsigned long long addr_dec, char *hex_tab, int iter)
{
	if (addr_dec > 16)
		conv_dec_to_hex(addr_dec / 16, hex_tab, ++iter);
	else
		if (iter == 0)
			write(1, "0", 1);
	write(1, &hex_tab[addr_dec % 16], 1);
}

void	print_hex_decimal(unsigned long long addr_dec)
{
	unsigned long long	check_zero;
	int					i;

	i = 0;
	check_zero = addr_dec;
	while (i++ < 14)
	{
		if (check_zero < 16)
			write(1, "0", 1);
		check_zero /= 16;
	}
	conv_dec_to_hex(addr_dec, "0123456789abcdef", 0);
	write(1, ": ", 2);
}

void	print_hex_text(unsigned char *text, int size)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (size > i)
			conv_dec_to_hex((unsigned long long)text[i], "0123456789abcdef", 0);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
	}
}

void	print_text(unsigned char *text, int size)
{
	int	i;

	i = -1;
	while (size > ++i)
	{
		if (text[i] < 32 || text[i] > 126)
			write(1, ".", 1);
		else
			write(1, &text[i], 1);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char		*text;
	unsigned int		i;
	int					size_print;

	i = 0;
	text = (unsigned char*)addr;
	while (size > i)
	{
		if (size > i + 16)
			size_print = 16;
		else
			size_print = size - i;
		print_hex_decimal((unsigned long long)&text[i]);
		print_hex_text(&text[i], size_print);
		print_text(&text[i], size_print);
		i += 16;
	}
	return (addr);
}

int	main(void)
{
	char	*str;

	str = "\nA new take on Aesops classic fable, and one of the most memorable stories for kids. When a shepherds youngest son is asked watch a flock of sheep, he cant help but find it breathtakingly booooooooooring. So to drum up a little “fun”, he decides to shout for the villagers to save him from a wolf hiding in a tree. When the villagers hear him shouting and come running, they dont find a wolf, just the boy rolling on the ground laughing. Having too much fun to stop now, he yells to the villagers again and again, each time with a new lie. The wolf is attacking from underground! From a hot air balloon! From a submarine! The wolf says to bring me cookies! Finally the villagers stop coming altogether, tired of being tricked. And that wouldnt be such a problem, if the wolf didnt decide to attack the flock right then and there… This rhyming story for kids is a quick, fun, fable with a modern twist. ";
	ft_print_memory(str, 907);
}