/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maputil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:40:14 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/27 16:03:36 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"

/*
** alloue un tableau de chaines de caractere initialisees avec '.'
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
		if ((str = (char *)malloc(sizeof(char) * taille_map)) == NULL)
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
*/

void	cleanup_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->taille_map)
	{
		map->map[i] = ft_memset(map->map[i], '.', map->taille_map);
		i++;
	}
}

/*
** affiche la map
** NB : on la libere en fin de fonction pour resoudre un pb de norminette
** ailleurs (limite des 25 lignes)
*/

int		display_map(t_map *map)
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
	free_map(map);
	return (1);
}

/*
** copie une map dans une autre ; les deux sont censees etre preallouees
** et de meme taille
*/

void	copy_map(t_map *cp_map, t_map *map)
{
	int xi;
	int yi;

	yi = 0;
	while (yi < map->taille_map)
	{
		xi = 0;
		while (xi < map->taille_map)
		{
			cp_map->map[yi][xi] = map->map[yi][xi];
			++xi;
		}
		++yi;
	}
}
