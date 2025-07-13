/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kreys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:38:55 by kreys             #+#    #+#             */
/*   Updated: 2025/07/12 17:32:34 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LEFTUP 'A'
#define LEFTDOWN 'A'
#define LEFTLEFT 'B'

#define RIGHTUP 'C'
#define RIGHTDOWN 'C'
#define RIGHTRIGHT 'B'

#define UPUP 'B'
#define DOWNDOWN 'B'

void	ft_putchat(char c);

static void	put_up(int x)
{
	int	x_sup;

	x_sup = 1;
	ft_putchat(LEFTUP);
	while (x > ++x_sup)
		ft_putchat(UPUP);
	if (x >= 2)
		ft_putchat(RIGHTUP);
	ft_putchat('\n');
}

static void	put_midl(int x, int y)
{
	int	y_sup;
	int	x_sup;

	y_sup = 1;
	while (y > ++y_sup)
	{
		ft_putchat(LEFTLEFT);
		x_sup = 1;
		while (x > ++x_sup)
			ft_putchat(' ');
		if (x > 1)
			ft_putchat(RIGHTRIGHT);
		ft_putchat('\n');
	}
}

static void	put_down(int x, int y)
{
	int	x_sup;

	x_sup = 1;
	if (y == 1)
		return ;
	ft_putchat(LEFTDOWN);
	while (x > ++x_sup)
		ft_putchat(DOWNDOWN);
	if (x >= 2)
		ft_putchat(RIGHTDOWN);
	ft_putchat('\n');
}

void	rush03(int x, int y)
{
	if (x < 1 || y < 1)
		return ;
	put_up(x);
	put_midl(x, y);
	put_down(x, y);
}
