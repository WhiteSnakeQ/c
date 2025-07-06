/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 02:10:26 by kreys             #+#    #+#             */
/*   Updated: 2025/07/03 02:11:13 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 1)
		return (0);
	j = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[argc - (j)][i])
			write(1, &argv[argc - (j)][i++], 1);
		write(1, "\n", 1);
	}
}