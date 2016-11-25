/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:55:23 by msrun             #+#    #+#             */
/*   Updated: 2016/11/25 13:29:30 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"

/*
** teste si la piece peut etre posee dans la map a la position (x,y)
** et l'insere dedans
** A FAIRE : ne pas tester au dela des bornes de la map !!!
*/

static int		test_insert_tetri(t_map *map, t_tetri *ptetri, int x, int y)
{
	int xi;
	int yi;

	xi = 0;
	while (xi < 4)
	{
		yi = 0;
		while (yi < 4)
		{
			if ((ptetri->tab[yi][xi] != '.') &&
					(((yi + y) >= map->taille_map) ||
					 (xi + x) >= map->taille_map))
				return (0);
			if ((((yi + y) <  map->taille_map) && (xi + x) <  map->taille_map)
				&& (map->map[yi + y][xi + x] != '.' && ptetri->tab[yi][xi] != '.'))
			{
				return (0);
			}
			yi++;
		}
		xi++;
	}
	// DEBUG
	ft_putstr("test_insert_tetri : (x, y) = ");;
	ft_putnbr(x);
	ft_putchar(',');
	ft_putnbr(y);
	ft_putchar('\n');
	// DEBUG
	xi = 0;
	while ((xi + x) < map->taille_map)
	{
		yi = 0;
		while((yi + y) < map->taille_map)
		{
			if (ptetri->tab[yi][xi] != '.')
				map->map[yi + y][xi + x] = ptetri->tab[yi][xi];
			yi++;
		}
		xi++;
	}
	return (1);
}

/*
** resolution du casse tete pour une map de taille fixe
** je prends la premiere piece, je la place en haut a gauche, j'essaie de poser
** la 2de a sa droite puis en dessous etc.
*/

static int		resolve_map(t_map *map, t_tetri *lst)
{
	int		xi;
	int		yi;
	t_map	*cp_map;

	// DEBUG
	ft_putstr("resolve_map\n");
	display_map(map);
	ft_putchar('\n');
	// DEBUG
	if (lst->isvalid == 0)
		return (0);
	if ((cp_map = alloc_map(map->taille_map)) == NULL)
		return (0);
	yi = 0;
	while (yi < map->taille_map)
	{
		xi = 0;
		while (xi < map->taille_map)
		{
			copy_map(cp_map, map);
			if (test_insert_tetri(cp_map, lst, xi, yi))
			{
				lst++;
				if (lst->isvalid)
				{
					if (resolve_map(cp_map, lst))
					{
						return (1);
					}
					lst--;
				}
				else
				{
					display_map(cp_map);
					free_map(cp_map);
					return (1);
				}
			}
			xi++;
		}
		yi++;
	}
	// DEBUG
	ft_putstr("resolve_map : impossible de resoudre sur cette map\n");
	// DEBUG
	return (0);
}

/*
** affiche la liste des tetriminos
*/

static void		print_tetri(t_tetri *lst)
{
	int ret;
	int i;

	ft_putstr("print_tetri\n");
	ret = 0;
	while (lst[ret].isvalid)
	{
		i = 0;
		while (i < 4)
		{
			ft_putstr(lst[ret].tab[i]);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		ret++;
	}
}

/*
** compte le nombre de tetriminos dans la liste pasee en parametre
*/

static int		count_tetri(t_tetri *lst)
{
	int ret;

	ret = 0;
	while (lst[ret].isvalid)
		ret++;
	return (ret);
}

/*
** calcul de l'entier lsuperieur le plus proche de la racine carree d'un int
** NB : cette fonction ne marche pas au de de racine carree de maxint
*/
#include <stdio.h>

static int		sqrt_approx(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i * i < nb)
		i++;
	return (i);
}

/*
** resolution du casse tete : comment faire rentrer dans un carre tous les
** tetriminos ?
** La taille max de la carte de resolution est de 15*15 mais on devrait resoudre
** en 11 ou 12 max
*/

int				ft_resolve(t_tetri *lst)
{
	int		taille_map;
	t_map	*map;

	if ((taille_map = sqrt_approx(count_tetri(lst) * 4)) == 0)
		return (0);
	// DEBUG
	print_tetri(lst);
	// DEBUG
	while (taille_map < 15)
	{
		// DEBUG
		ft_putstr("taille map : ");
		ft_putnbr(taille_map);
		ft_putchar('\n');
		// DEBUG
		if ((map = alloc_map(taille_map)) == NULL)
			return (0);
		if (resolve_map(map, lst))
			return (1);
		free_map(map);
		taille_map++;
	}
	return (0);
}
