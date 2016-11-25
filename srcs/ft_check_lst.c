/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:52:28 by msrun             #+#    #+#             */
/*   Updated: 2016/11/25 18:04:27 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

/*
** Verrification 4 cases dans le carre
*/

int		ft_check_nbdiese(t_tetri *lst)
{
	int i;
	int y;
	int z;
	int nb;

	i = 0;
	while (lst[i].isvalid == 1)
	{
		y = 0;
		nb = 0;
		while (y < 4)
		{
			z = -1;
			while (++z < 5)
			{
				if (lst[i].tab[y][z] == '#')
					++nb;
			}
			++y;
		}
		if (nb != 4)
			return (1);
		++i;
	}
	return (0);
}

/*
**	Verification que les 4 cases forment une piece valide
*/

int		ft_check_place(t_tetri lst)
{
	int x;
	int y;
	int i;

	y = -1;
	i = 0;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (lst.tab[y][x] == '#')
			{
				if (lst.tab[y + 1][x] == '#')
					i++;
				if (lst.tab[y - 1][x] == '#')
					i++;
				if (lst.tab[y][x + 1] == '#')
					i++;
				if (lst.tab[y][x - 1] == '#')
					i++;
			}
	}
	if (i < 6)
		return (1);
	return (0);
}

/*
** Verification si les 4 cases forme une piece
*/

int		ft_check_form(t_tetri *lst)
{
	int i;
	int nb;

	i = 0;
	while (lst[i].isvalid == 1)
	{
		nb = 0;
		if (ft_check_place(lst[i]) == 1)
			return (1);
		++i;
	}
	return (0);
}

int		ft_check_lst(t_tetri *lst)
{
	int err;

	err = 0;
	err = ft_check_nbdiese(lst);
	if (err != 0)
		return (err);
	err = ft_check_form(lst);
	return (err);
}
