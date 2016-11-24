/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maputil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:40:14 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/24 16:34:47 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"

/*
** alloue un tableau de chaines de caractere initialisees avec '.'
** NB : pour simplifier le debugging, on prevoit des chaines terminee par 0
*/

char	**alloc_map(int taille_map)
{
	int		i;
	char	*str;
	char	**map;

	if ((map = (char **)malloc(sizeof(char *) * taille_map)) == NULL)
		return (NULL);
	i = 0;
	while (i < taille_map)
	{
		if ((str = (char *)malloc(sizeof(char) * (taille_map + 1))) == NULL)
			return (NULL);
		str[taille_map] = 0;
		map[i] = ft_memset(str, '.', taille_map);
		i++;
	}
	return (map);
}

/*
** suppression propre de la memoire
*/

void	free_map(char **map, int taille_map)
{
	int i;

	i = 0;
	while (i < taille_map)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/*
** nettoyage de la map passee en param
*/

void	cleanup_map(char **map, int taille_map)
{
	int i;

	i = 0;
	while (i < taille_map)
	{
		map[i] = ft_memset(map[i], '.', taille_map);
		i++;
	}
}

/*
** affiche la map
*/

void	display_map(char **map, int taille_map)
{
	int xi;
	int yi;

	yi = 0;
	while (yi < taille_map)
	{
		xi = 0;
		while (xi < taille_map)
		{
			ft_putchar(map[yi][xi]);
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}

/*
** copie une map dans une autre ; les deux sont censees etre preallouees
** et de meme taille
*/

void	copy_map(char **cp_map, char **map, int taille_map)
{
	int xi;
	int yi;

	yi = 0;
	while (yi < taille_map)
	{
		xi = 0;
		while (xi < taille_map)
		{
			cp_map[yi][xi] = map[yi][xi];
			xi++;
		}
		yi++;
	}
}
