/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:11:45 by msrun             #+#    #+#             */
/*   Updated: 2016/11/26 11:46:36 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_move_top(t_tetri *lst, int pos)
{
	int x;
	int y;

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 4)
		{
			lst[pos].tab[y][x] = lst[pos].tab[y + 1][x];
			++x;
		}
		++y;
	}
	lst[pos].tab[3][0] = '.';
	lst[pos].tab[3][1] = '.';
	lst[pos].tab[3][2] = '.';
	lst[pos].tab[3][3] = '.';
}

void	ft_move_left(t_tetri *lst, int pos)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 3)
		{
			lst[pos].tab[y][x] = lst[pos].tab[y][x + 1];
			++x;
		}
		++y;
	}
	lst[pos].tab[0][3] = '.';
	lst[pos].tab[1][3] = '.';
	lst[pos].tab[2][3] = '.';
	lst[pos].tab[3][3] = '.';
}

void	ft_replace_if_void(t_tetri *lst, int pos)
{
	while (lst[pos].tab[0][0] != '#' && lst[pos].tab[0][1] != '#' &&
			lst[pos].tab[0][2] != '#' && lst[pos].tab[0][3] != '#')
		ft_move_top(lst, pos);
	while (lst[pos].tab[0][0] != '#' && lst[pos].tab[1][0] != '#' &&
			lst[pos].tab[2][0] != '#' && lst[pos].tab[3][0] != '#')
		ft_move_left(lst, pos);
}

void	ft_replace_to_alpha(t_tetri *lst, int pos)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (lst[pos].tab[y][x] == '#')
				lst[pos].tab[y][x] = pos + 'A';
			++x;
		}
		++y;
	}
}

void	ft_replace(t_tetri *lst)
{
	int i;

	i = 0;
	while (lst[i].isvalid == 1)
	{
		ft_replace_if_void(lst, i);
		ft_replace_to_alpha(lst, i);
		i++;
	}
}
