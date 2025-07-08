/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 01:37:24 by kreys             #+#    #+#             */
/*   Updated: 2025/07/08 18:18:06 by kreys            ###   ########.fr       */
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

int	main(void)
{
	char	*str;

	printf("        EXample       \n");
	printf("0123456789abcdef: 0000 0000 0000 0000 0000 0000 0000 0000 text------------\n\n");
	str = "The strlcpy() and strlcat() functions copy and concatenate strings respectively. They are designed to be safer, more consistent, and less error prone replacements for strncpy(3) and strncat(3). Unlike those functions, strlcpy() and strlcat() take the full size of the buffer (not just the length) and guarantee to NUL-terminate the result (as long as size is larger than 0 or, in the case of strlcat(), as long as there is at least one byte free in dst). Note that a byte for the NUL should be included in size. Also note that strlcpy() and strlcat() only operate on true ''C'' strings. This means that for strlcpy() src must be NUL-terminated and for strlcat() both src and dst must be NUL-terminated.";
	ft_print_memory(str, 702);
	printf("\n\n");
	str = "The swindlers showed him the clothes. But again, he saw nothing. He thought: am I so terribly stupid? No one should ever know about this. So he told the emperor, the clothes were beautiful. The weavers laughed contentedly. They asked for more money and put it all in their own pockets.Then the emperor sent an honest man. But this man too saw nothing at all. He was sure he was not stupid, so he then he certainly wasn’t honest. Of course, no one was supposed to know that. So he too pretended to be honest and said the clothes were beautiful.Then the emperor went to see for himself. He took a lot of people with him, including the clever and the honest man. They said, look Your Majesty ,how beautiful those clothes are. They thought that the other people could see the clothes.The emperor thought, “I can’t see anything. Am I stupid or dishonest? That would be terrible. So he too pretended to see the clothes. All his people didn’t see anything either but said the clothes were beautiful.The next day, there was a festive procession. The whole night before, the impostors pretended to work hard. In the morning, the Emperor and his court went to see them again, and the weavers said: “The clothes are as light as cobwebs, it looks as if you aren’t wearing anything at all, but that is what makes them so beautiful.Everyone shouted, but no one could see anything, because there was nothing to see. The Emperor took off his old clothes and put on the “new clothes”. He could not see anything in the mirror but everyone shouted: how beautiful those clothes are!";
	ft_print_memory(str, 1578);
}
