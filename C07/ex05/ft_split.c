/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:59:11 by kreys             #+#    #+#             */
/*   Updated: 2025/07/21 05:39:25 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

int	find_char(char *str, char to_find)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == to_find)
			return (i);
	}
	return (-1);
}

int	get_size_of_world(char *str, char *charset)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i == 0 && find_char(charset, str[i]) >= 0)
			return (-1);
		if (find_char(charset, str[i]) >= 0)
			return (i);
	}
	return (i);
}

int	get_size_str(char *str, char *charset)
{
	int		j;
	int		i;
	int		len;
	int		size_strs;

	i = -1;
	size_strs = 0;
	len = 0;
	while (str[len])
		len++;
	while (str && ++i < len)
	{
		j = get_size_of_world(&str[i], charset);
		if (j >= 0)
		{
			size_strs++;
			i += j;
		}
	}
	return (size_strs);
}

char	*make_string(char *str, char *charset, int *i)
{
	int		size_new_str;
	int		j;
	char	*new_str;

	size_new_str = -1;
	while (size_new_str < 0)
		size_new_str = get_size_of_world(&str[(*i)++], charset);
	(*i)--;
	new_str = malloc(sizeof(char) * (size_new_str + 1));
	if (new_str)
	{
		j = 0;
		new_str[size_new_str] = '\0';
		while (size_new_str > j)
			new_str[j++] = str[(*i)++];
	}
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	int		size_str;
	int		j;
	int		i;
	char	**strs;

	j = 0;
	i = 0;
	size_str = get_size_str(str, charset);
	strs = malloc(sizeof(char *) * (size_str + 1));
	while (strs && str && j < size_str)
		strs[j++] = make_string(str, charset, &i);
	if (strs)
		strs[size_str] = NULL;
	return (strs);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**strs;

	if (argc != 3)
		return (0);
	strs = ft_split(argv[1], argv[2]);
	i = 0;
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		free(strs[i++]);
	}
	free(strs);
}
