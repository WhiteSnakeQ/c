/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_pos_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:09:23 by kreys             #+#    #+#             */
/*   Updated: 2025/07/20 01:16:28 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

int		str_len(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*fill_str_increment(int size);
char	**create_strs(int size);
int		get_variants(int size);

void	add_variant(char **all_str, char *new_str)
{
	static char	**all_st;
	static int	i = 0;

	if (all_str)
	{
		all_st = all_str;
		return ;
	}
	else
		ft_strcpy(all_st[i++], new_str);
}

void	recur_permute(int index, char str[5])
{
	int		i;
	char	tmp;

	if (index == str_len(str))
	{
		add_variant(NULL, str);
		return ;
	}
	i = index - 1;
	while (++i < str_len(str))
	{
		tmp = str[index];
		str[index] = str[i];
		str[i] = tmp;
		recur_permute(index + 1, str);
		tmp = str[index];
		str[index] = str[i];
		str[i] = tmp;
	}
}

char	**get_all_poss_var(int size)
{
	int		all;
	char	**all_str;
	char	*str;

	all = get_variants(size);
	all_str = create_strs(all);
	if (!all_str)
		return (all_str);
	str = fill_str_increment(size);
	add_variant(all_str, NULL);
	recur_permute(0, str);
	free(str);
	return (all_str);
}
