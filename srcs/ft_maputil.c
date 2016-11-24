/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maputil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:40:14 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/24 18:26:13 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"

/*
** alloue un tableau de chaines de caractere initialisees avec '.'
** NB : pour eviter les depassements de memoire, on ajoute 3 caracteres aux
** chaines de caracteres
*/

t_map	*alloc_map(int taille_map)
{
	int		i;
	char	*str;
	t_map	*map;
	char	**pmap;

	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	if ((pmap = (char **)malloc(sizeof(char *) * taille_map)) == NULL)
		return (NULL);
	i = 0;
	while (i < taille_map)
	{
		if ((str = (char *)malloc(sizeof(char) * (taille_map + 3))) == NULL)
			return (NULL);
		pmap[i] = ft_memset(str, '.', taille_map);
		i++;
	}
	map->map = pmap;
	map->taille_map = taille_map;
	return (map);
}

/*
** suppression propre de la memoire
*/

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->taille_map)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

/*
** nettoyage de la map passee en param
** NB: 3 caracteres de plus pour les chaines de caractere
*/

void	cleanup_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->taille_map)
	{
		map->map[i] = ft_memset(map->map[i], '.', map->taille_map + 3);
		i++;
	}
}

/*
** affiche la map
*/

void	display_map(t_map *map)
{
	int xi;
	int yi;

	yi = 0;
	while (yi < map->taille_map)
	{
		xi = 0;
		while (xi < map->taille_map)
		{
			ft_putchar(map->map[yi][xi]);
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}

/*
** copie une map dans une autre ; les deux sont censees etre preallouees
** et de meme taille
** NB: je gere 3 car de plus dans les chaines de caracteres
*/

void	copy_map(t_map *cp_map, t_map *map)
{
	int xi;
	int yi;

	yi = 0;
	while (yi < map->taille_map)
	{
		xi = 0;
		while (xi < map->taille_map + 3)
		{
			cp_map->map[yi][xi] = map->map[yi][xi];
			xi++;
		}
		yi++;
	}
}
