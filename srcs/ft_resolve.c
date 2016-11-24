/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:55:23 by msrun             #+#    #+#             */
/*   Updated: 2016/11/24 16:10:31 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"

/*
** teste si la piece peut etre posee dans la map a la position (x,y)
** et l'insere dedans
** A FAIRE : ne pas tester au dela des bornes de la map !!!
*/

static int		test_insert_tetri(char **map,\
		int taille_map, t_tetri *ptetri, int x, int y)
{
	int xi;
	int yi;

	xi = 0;
	yi = 0;
	while (((xi + x) < taille_map) && ((yi + y) < taille_map))
	{
		if (map[yi + y][xi + x] != '.' && ptetri->tab[yi][xi] != '.')
		{
			return (0);
		}
		xi++;
		yi++;
	}
	xi = 0;
	yi = 0;
	while (((xi + x) < taille_map) && ((yi + y) < taille_map))
	{
		map[yi + y][xi + x] = ptetri->tab[yi][xi];
		xi++;
		yi++;
	}
	return (1);
}

/*
** resolution du casse tete pour une map de taille fixe
** je prends la premiere piece, je la place en haut a gauche, j'essaie de poser
** la 2de a sa droite puis en dessous etc.
*/

static int		resolve_map(char **map, int taille_map, t_tetri *lst)
{
	int		xi;
	int		yi;
	char	**cp_map;

	if (lst->isvalid == 0)
		return (0);
	if ((cp_map = alloc_map(taille_map)) == NULL)
		return (0);
	yi = 0;
	while (yi < taille_map)
	{
		xi = 0;
		while (xi < taille_map)
		{
			copy_map(cp_map, map, taille_map);
			if (test_insert_tetri(cp_map, taille_map, lst, xi, yi))
			{
				lst++;
				if (lst->isvalid)
				{
					if (resolve_map(cp_map, taille_map, lst))
						return (1);
				}
				else
				{
					display_map(cp_map, taille_map);
					free_map(cp_map, taille_map);
					return (1);
				}
			}
			xi++;
		}
		yi++;
	}
	return (0);
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
** resolution du casse tete : comment faire rentrer dans un carre tous les
** tetriminos ?
** La taille max de la carte de resolution est de 15*15 mais on devrait resoudre
** en 11 ou 12 max
*/

int				ft_resolve(t_tetri *lst)
{
	int		taille_map;
	char	**map;

	if ((taille_map = ft_sqrt(count_tetri(lst))) == 0)
		return (0);
	while (taille_map < 15)
	{
		if ((map = alloc_map(taille_map)) == NULL)
			return (0);
		if (resolve_map(map, taille_map, lst))
			return (1);
		free_map(map, taille_map);
	}
	return (0);
}
