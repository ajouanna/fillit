/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maputil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:40:14 by ajouanna          #+#    #+#             */
/*   Updated: 2016/11/24 11:54:16 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"

/*
** compte le nombre de tetriminos dans la liste pasee en parametre
*/

int		count_tetri(t_tetri *lst)
{
	int ret;

	ret = 0;
	while (lst[ret].isvalid)
		ret++;
	return (ret);
}

/*
** alloue un tableau de chaines de caractere initialisees avec ' '
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
		map[i] = ft_memset(str, ' ', taille_map);
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

void cleanup_map(char **map, int taille_map)
{
	int i;

	i = 0;
	while (i < taille_map)
	{
		map[i] = ft_memset(map[i], ' ', taille_map);
		i++;	
	}
}
