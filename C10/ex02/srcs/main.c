/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:35:53 by kreys             #+#    #+#             */
/*   Updated: 2025/07/06 10:03:06 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_tail.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	if (parse_error(argv, check_argv(argc, argv)))
		return (0);
	if (str_len(argv[1]) != 2)
		tail_f(argc, argv, ft_atoi(argv[1] + 2));
	else
		tail_f(argc, argv, ft_atoi(argv[2]));
}
