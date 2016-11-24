/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:55:23 by msrun             #+#    #+#             */
/*   Updated: 2016/11/24 11:52:19 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"

/*
** resolution du casse tete pour une map de taille fixe
*/

int		resolve_map(char **map, int taille_map, t_tetri *lst)
{
	(void)map;
	(void)taille_map;
	(void)lst;
	return (0);
}

/*
** resolution du casse tete : comment faire rentrer dans un carre tous les
** tetriminos ?
** La taille max de la carte de resolution est de 15*15 mais on devrait resoudre
** en 11 ou 12 max
*/

int		ft_resolve(t_tetri *lst)
{
	int		taille_map;
	char	**map;

	if ((taille_map = ft_sqrt(count_tetri(lst))) == 0)
		return (0);
	while (taille_map < 12)
	{
		if ((map = alloc_map(taille_map)) == NULL)
			return (0);
		if (resolve_map(map, taille_map, lst))
			return (1);
		free_map(map, taille_map);
	}
	return (0);
}
