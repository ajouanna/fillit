/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:52:28 by msrun             #+#    #+#             */
/*   Updated: 2016/11/24 16:44:39 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdio.h>

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

int		ft_check_place(t_tetri *lst, int nblst, int y, int x)
{
	if (lst[nblst].tab[y + 1][x] == '#' || lst[nblst].tab[y - 1][x] == '#' ||
			lst[nblst].tab[y][x + 1] == '#' || lst[nblst].tab[y][x - 1] == '#')
		return (0);
	return (1);
}

/*
** Verification si les 4 cases forme une piece
*/

int		ft_check_form(t_tetri *lst)
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
				if (lst[i].tab[y][z] == '#')
				{
					if (ft_check_place(lst, i, y, z) == 1)
						return (1);
				}
			++y;
		}
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
